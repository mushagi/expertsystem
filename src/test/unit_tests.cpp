#include <string>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "expertsystem.hpp"

TEST_CASE( "testing node class" ){
	Node node('A');
	SECTION("valid class symbol"){
		REQUIRE(node.getSymbol() == 'A');
	}

	SECTION("adding index"){
		node.addToListOfIndex(1);
		REQUIRE(node.getListOfIndex().front() == 1);

		node.addToListOfIndex(8);
		REQUIRE(node.getListOfIndex().back() == 8);

		node.addToListOfIndex(60);
		REQUIRE(node.getListOfIndex().back() == 60);

		REQUIRE(node.getListOfIndex().size() == 3);
	}
	SECTION("initialising node to false")
	{
		Node nodeInit('B');
		REQUIRE(node.getStatus() == 0);
	}

	SECTION("Set initial facts")
	{
		node.setReason("Initial fact given");
		REQUIRE(node.getReason() == "Initial fact given");
	}

}

TEST_CASE("testing rule class")
{
	Nodes nodes;
	Rule rule("A+B+C=>D", &nodes);

	REQUIRE(rule.toString() == "A+B+C=>D");
	SECTION("Complex rule")
	{
		Nodes nodes;
		Rule ruleComplex(" A + B + D             => G ", &nodes);
		REQUIRE(ruleComplex.toString() == "A+B+D=>G");
	}
	SECTION("get rid of the comments ")
	{
		Nodes nodes;
		Rule ruleComplex2(" A + B + D             => G        # HEllo there stranger", &nodes);
		REQUIRE(ruleComplex2.toString() == "A+B+D=>G");
	}

	SECTION("add nodes while reading a rule")
	{
		Nodes nodes;
		Rule rule1("A+B+C=>N", &nodes);
		REQUIRE(nodes.size() == 4);
	}
	SECTION("Seperate sides"){
		Nodes nodes;
		Rule rule("A+B+C=>C", &nodes);
		REQUIRE(rule.getLeftSide() == "A+B+C");
		REQUIRE(rule.getRightSide() == "C");
	}

	SECTION("Seperate sides, right side with multiple variables"){
		Nodes nodes;
		Rule rule("A+B+C=>C+S", &nodes);
		REQUIRE(rule.getLeftSide() == "A+B+C");
		REQUIRE(rule.getRightSide() == "C+S");
	}

	SECTION("Get side nodes")
	{
		Nodes nodes;

		Rule rule("A+B=>C", &nodes);
		REQUIRE(rule.getLeftSideNodes().front() == 'A');
		REQUIRE(rule.getLeftSideNodes().back()== 'B');
		REQUIRE(rule.getLeftSideNodes().size() == 2);
	}
}


TEST_CASE("Query class")
{
	SECTION("empty query")
	{
		Nodes nodes;
		Rules rules;
		rules.add(Rule("A+B+C=>C", &nodes));
		Query query("?     ", &nodes);
		REQUIRE(query.getNodes().size() == 0);
		REQUIRE(query.getQuery() == "?");
	}

	SECTION("add nodes to query list")
	{
		Nodes nodes;

		Rules rules;
		rules.add(Rule("A+B+C=>D", &nodes));
		Query query("?AB", &nodes);

		REQUIRE(query.getQuery() == "?AB");
		REQUIRE(query.getNodes().front()->getSymbol() == 'A');

		REQUIRE(query.getNodes().front()->getSymbol() == nodes.getNodes()->front().getSymbol());
		REQUIRE(query.getNodes().front() == &nodes.getNodes()->front());
		REQUIRE(query.getNodes().front()->getStatus() == 0);
		query.getNodes().front()->setStatus(4);
		REQUIRE(query.getNodes().front()->getStatus() == 4);
		REQUIRE(nodes.getNodes()->front().getStatus() == 4);

		REQUIRE(query.getNodeByChar('A')->getStatus() == 4);
		//query
	}

}

TEST_CASE("Testing the rules class")
{
	SECTION("number of rules")
	{
		Nodes nodes;
		Rules rules;
		REQUIRE(rules.size() == 0);

		rules.add(Rule("A+B+=>F", &nodes));
		REQUIRE(rules.size() == 1);

		rules.add(Rule("A+B+=>F", &nodes));
		REQUIRE(rules.size() == 2);
	}
}

TEST_CASE("Testing nodes class")
{
	SECTION("Testing a node that doesn't exist on the right side"){
		Nodes nodes;

		Rules rules;
		rules.add(Rule("A+B=>C", &nodes));
		rules.add(Rule("A=>D", &nodes));
		rules.add(Rule("Q=>C", &nodes));
		REQUIRE(nodes.getNodeByChar('Q')->getListOfIndex().size() == 0);
	}
	SECTION("Testing a node that exist on the right side"){
		Nodes nodes;
		Rules rules;
		rules.add(Rule("A+B=>C", &nodes));
		rules.add(Rule("A=>D", &nodes));
		rules.add(Rule("Q=>C", &nodes));
		REQUIRE(nodes.getNodeByChar('D')->getListOfIndex().size() == 1);
	}

	SECTION("Testing a node that exist on the right side, alot of times"){
		Nodes nodes;
		Rules rules;
		Rule rule("A+B=>C+D", &nodes);
		REQUIRE(nodes.getNodeByChar('B')->getListOfIndex().size() == 0);
	}
}

TEST_CASE("testing inference engine")
{
	SECTION("testing initial updated facts"){
		Nodes nodes;
		Rules rules;
		rules.add(Rule("A+B+C=>E+D", &nodes));
		Query query("?AB", &nodes);
		string facts = "A";
		InferenceEngine engine(rules, nodes, query, facts);
		REQUIRE(engine.getNodeBySymbol('A')->getStatus() == 1);
	}
	SECTION("simplest inference test")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A+B=>C", &nodes));
		Query query("?C", &nodes);
		string facts("A");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "C=FALSE\n");
	}
	SECTION("simple test")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A+B=>C", &nodes));
		Query query("?C", &nodes);
		string facts("");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "C=FALSE\n");
	}

	SECTION("Test negation")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("!A+!B=>!C", &nodes));
		Query query("?C", &nodes);
		string facts("A");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "C=FALSE\n");
	}
/*
	SECTION("contradiction")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A => C", &nodes));
		rules.add(Rule("A + B => !C", &nodes));
		Query query("?C", &nodes);
		string facts("AB");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "C=FALSE\n");
	}

	SECTION("contradiction part 2")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A => C", &nodes));
		rules.add(Rule("A + B => C + !(C +D)", &nodes));
		Query query("?C", &nodes);
		string facts("AB");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "C=FALSE\n");
	}
*/
	SECTION("Test 1 Part 1")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B => A", &nodes));
		rules.add(Rule("D + E => B ", &nodes));
		rules.add(Rule("G + H => F", &nodes));
		rules.add(Rule("I + J => G", &nodes));
		rules.add(Rule("G => H", &nodes));
		rules.add(Rule("L + M => K", &nodes));
		rules.add(Rule("O + P => L + N", &nodes));
		rules.add(Rule("N => M", &nodes));
		Query query("?AFKP", &nodes);
		string facts("DEIJOP");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\nF=TRUE\nK=TRUE\nP=TRUE\n");
	}
	SECTION("Test 1 Part 1")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B => A", &nodes));
		rules.add(Rule("D + E => B ", &nodes));
		rules.add(Rule("G + H => F", &nodes));
		rules.add(Rule("I + J => G", &nodes));
		rules.add(Rule("G => H", &nodes));
		rules.add(Rule("L + M => K", &nodes));
		rules.add(Rule("O + P => L + N", &nodes));
		rules.add(Rule("N => M", &nodes));
		Query query("?AFKP", &nodes);
		string facts("DEIJOP");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\nF=TRUE\nK=TRUE\nP=TRUE\n");
	}
	SECTION("Test 1 Part 1")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B => A", &nodes));
		rules.add(Rule("D + E => B ", &nodes));
		rules.add(Rule("G + H => F", &nodes));
		rules.add(Rule("I + J => G", &nodes));
		rules.add(Rule("G => H", &nodes));
		rules.add(Rule("L + M => K", &nodes));
		rules.add(Rule("O + P => L + N", &nodes));
		rules.add(Rule("N => M", &nodes));
		Query query("?AFKP", &nodes);
		string facts("DEIJOP");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\nF=TRUE\nK=TRUE\nP=TRUE\n");
	}
	SECTION("Test 1 Part 1")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B => A", &nodes));
		rules.add(Rule("D + E => B ", &nodes));
		rules.add(Rule("G + H => F", &nodes));
		rules.add(Rule("I + J => G", &nodes));
		rules.add(Rule("G => H", &nodes));
		rules.add(Rule("L + M => K", &nodes));
		rules.add(Rule("O + P => L + N", &nodes));
		rules.add(Rule("N => M", &nodes));
		Query query("?AFKP", &nodes);
		string facts("DEIJOP");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\nF=TRUE\nK=TRUE\nP=TRUE\n");
	}
	SECTION("Test 1 Part 1")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B => A", &nodes));
		rules.add(Rule("D + E => B ", &nodes));
		rules.add(Rule("G + H => F", &nodes));
		rules.add(Rule("I + J => G", &nodes));
		rules.add(Rule("G => H", &nodes));
		rules.add(Rule("L + M => K", &nodes));
		rules.add(Rule("O + P => L + N", &nodes));
		rules.add(Rule("N => M", &nodes));
		Query query("?AFKP", &nodes);
		string facts("DEIJOP");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\nF=TRUE\nK=TRUE\nP=TRUE\n");
	}
	SECTION("Test 1 Part 2")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B => A", &nodes));
		rules.add(Rule("D + E => B ", &nodes));
		rules.add(Rule("G + H => F", &nodes));
		rules.add(Rule("I + J => G", &nodes));
		rules.add(Rule("G => H", &nodes));
		rules.add(Rule("L + M => K", &nodes));
		rules.add(Rule("O + P => L + N", &nodes));
		rules.add(Rule("N => M", &nodes));
		Query query("?AFKP", &nodes);
		string facts("DEIJP");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\nF=TRUE\nK=FALSE\nP=TRUE\n");
	}

	SECTION("Test 2 Part 1 OR")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B + C => A", &nodes));
		rules.add(Rule("D | E => B", &nodes));
		rules.add(Rule("B => C", &nodes));
		Query query("?A", &nodes);
		string facts("");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=FALSE\n");
	}

	SECTION("Test 2 Part 2")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B + C => A", &nodes));
		rules.add(Rule("D | E => B", &nodes));
		rules.add(Rule("B => C", &nodes));
		Query query("?A", &nodes);
		string facts("D");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\n");
	}

	SECTION("Test 2 Part 3")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B + C => A", &nodes));
		rules.add(Rule("D | E => B", &nodes));
		rules.add(Rule("B => C", &nodes));
		Query query("?A", &nodes);
		string facts("E");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\n");
	}

	SECTION("Test 2 Part 3")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B + C => A", &nodes));
		rules.add(Rule("D | E => B", &nodes));
		rules.add(Rule("B => C", &nodes));
		Query query("?A", &nodes);
		string facts("DE");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\n");
	}


	SECTION("Test 3 Part 1 XOR")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B + C => A", &nodes));
		rules.add(Rule("D ^ E => B", &nodes));
		rules.add(Rule("B => C", &nodes));
		Query query("?A", &nodes);
		string facts("");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=FALSE\n");
	}

	SECTION("Test 3 Part 2")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B + C => A", &nodes));
		rules.add(Rule("D ^ E => B", &nodes));
		rules.add(Rule("B => C", &nodes));
		Query query("?A", &nodes);
		string facts("D");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\n");
	}


	SECTION("Test 3 Part 3")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B + C => A", &nodes));
		rules.add(Rule("D ^ E => B", &nodes));
		rules.add(Rule("B => C", &nodes));
		Query query("?A", &nodes);
		string facts("E");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\n");
	}

	SECTION("Test 3 Part 3")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B + C => A", &nodes));
		rules.add(Rule("D ^ E => B", &nodes));
		rules.add(Rule("B => C", &nodes));
		Query query("?A", &nodes);
		string facts("DE");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=FALSE\n");
	}

	SECTION("Test 4 Part 1 contradicitons")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B => A", &nodes));
		rules.add(Rule("C => A", &nodes));
		Query query("?A", &nodes);
		string facts("");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=FALSE\n");
	}
	SECTION("Test 4 Part 2")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B => A", &nodes));
		rules.add(Rule("C => A", &nodes));
		Query query("?A", &nodes);
		string facts("B");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\n");
	}
	SECTION("Test 4 Part 3")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B => A", &nodes));
		rules.add(Rule("C => A", &nodes));
		Query query("?A", &nodes);
		string facts("C");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\n");
	}
	SECTION("Test 4 Part 4")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B => A", &nodes));
		rules.add(Rule("C => A", &nodes));
		Query query("?A", &nodes);
		string facts("BC");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\n");
	}

	SECTION("Test 5 Part 1")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A | B + C => E", &nodes));
		rules.add(Rule("(F | G) + H => E", &nodes));
		Query query("?E", &nodes);
		string facts("");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "E=FALSE\n");
	}

	SECTION("Test 5 Part 2")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A | B + C => E", &nodes));
		rules.add(Rule("(F | G) + H => E", &nodes));
		Query query("?E", &nodes);
		string facts("A");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "E=TRUE\n");
	}

	SECTION("Test 5 Part 3")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A | B + C => E", &nodes));
		rules.add(Rule("(F | G) + H => E", &nodes));
		Query query("?E", &nodes);
		string facts("B");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "E=FALSE\n");
	}


	SECTION("Test 5 Part 4")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A | B + C => E", &nodes));
		rules.add(Rule("(F | G) + H => E", &nodes));
		Query query("?E", &nodes);
		string facts("C");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "E=FALSE\n");
	}

	SECTION("Test 5 Part 5")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A | B + C => E", &nodes));
		rules.add(Rule("(F | G) + H => E", &nodes));
		Query query("?E", &nodes);
		string facts("AC");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "E=TRUE\n");
	}

	SECTION("Test 5 Part 6")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A | B + C => E", &nodes));
		rules.add(Rule("(F | G) + H => E", &nodes));
		Query query("?E", &nodes);
		string facts("BC");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "E=TRUE\n");
	}

	SECTION("Test 5 Part 7")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A | B + C => E", &nodes));
		rules.add(Rule("(F | G) + H => E", &nodes));
		Query query("?E", &nodes);
		string facts("F");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "E=FALSE\n");
	}

	SECTION("Test 5 Part 8")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A | B + C => E", &nodes));
		rules.add(Rule("(F | G) + H => E", &nodes));
		Query query("?E", &nodes);
		string facts("G");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "E=FALSE\n");
	}
	SECTION("Test 5 Part 9")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A | B + C => E", &nodes));
		rules.add(Rule("(F | G) + H => E", &nodes));
		Query query("?E", &nodes);
		string facts("H");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "E=FALSE\n");
	}
	SECTION("Test 5 Part 10")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A | B + C => E", &nodes));
		rules.add(Rule("(F | G) + H => E", &nodes));
		Query query("?E", &nodes);
		string facts("FH");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "E=TRUE\n");
	}
	SECTION("Test 5 Part 11")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("A | B + C => E", &nodes));
		rules.add(Rule("(F | G) + H => E", &nodes));
		Query query("?E", &nodes);
		string facts("GH");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "E=TRUE\n");
	}

	SECTION("Test 6 Part 1 negate")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B + !C=> A", &nodes));
		Query query("?A", &nodes);
		string facts("");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=FALSE\n");
	}
	SECTION("Test 6 Part 2")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B + !C=> A", &nodes));
		Query query("?A", &nodes);
		string facts("B");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=TRUE\n");
	}
	SECTION("Test 6 Part 3")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B + !C=> A", &nodes));
		Query query("?A", &nodes);
		string facts("C");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=FALSE\n");
	}
	SECTION("Test 6 Part 4")
	{
		Nodes nodes;
		Rules rules;

		rules.add(Rule("B + !C=> A", &nodes));
		Query query("?A", &nodes);
		string facts("BC");
		InferenceEngine engine(rules, nodes, query, facts);
		engine.execute();
		REQUIRE(engine.getResults() == "A=FALSE\n");
	}
}

TEST_CASE("RPN Calculator")
{
	SECTION("Error tests")
	{
		int res = rpnCalculater("");
		REQUIRE(res == 0);
	}
	SECTION("Simple test")
	{
		int res = rpnCalculater("1 1 +");
		REQUIRE(res == 2);

		res = rpnCalculater("4 9 2 + +");
		REQUIRE(res == 15);

		res = rpnCalculater("3 6 9 * 6 + +");
		REQUIRE(res == 63);
	}
	SECTION("a bit advanced")
	{
		int res = rpnCalculater("50 10 25 + -");
		REQUIRE(res == 15);
	}

	SECTION("Advanced")
	{

		int res = rpnCalculater("78 326 542 96 1452 36 965 % - * / + +");
		REQUIRE(res == 404);

		res = rpnCalculater("-111 45 123 * 26 73 + + - 78 * -85 / 123 -");
		REQUIRE(res == 5148);

		res = rpnCalculater("3 6 + 8 4 / 5 / +");
		REQUIRE(res == 9);
	}
}


TEST_CASE("Convert infix to prefix")
{

	SECTION("Error tests")
	{
		//2+2
	}
	SECTION("Simple test")
	{
		string result = rpn_conv("7 + 2");
		REQUIRE(result == "7 2 +");
		result = rpn_conv("7 + 2 - 3");
		REQUIRE(result == "7 2 + 3 -");
	}

	SECTION("a bit advanced")
	{

		string result = rpn_conv("100 * 5 / 8 / 40 + 40");
		REQUIRE(result == "100 5 * 8 / 40 / 40 +");
		REQUIRE( (100 * 5 / 8 / 40 + 40) == rpnCalculater(result));
	}

	SECTION("Advanced")
	{
		string result = rpn_conv("100 * 50 - 54 / 2 - 4900 + 1 - 74 + 4 - 2");
		REQUIRE(result == "100 50 * 54 2 / - 4900 - 1 + 74 - 4 + 2 -");
		REQUIRE((100 * 50 - 54 / 2 - 4900 + 1 - 74 + 4 - 2) == rpnCalculater(result));
		result = rpn_conv("100 * 3466 / 345 / 4535 * 35 - 5000 * 5345 - 3532 + 100000000");
		REQUIRE((100 * 3466 / 345 / 4535 * 35 - 5000 * 5345 - 3532 + 100000000) == rpnCalculater(result));
	}

	SECTION("Brackets")
	{
		string result = rpn_conv("( 1 + 2 )");
		REQUIRE(result == "1 2 +");

		result = rpn_conv("1 + 2 / ( 10 + 1 / 3 )");
		REQUIRE(result == "1 2 10 1 3 / + / +");
		REQUIRE(1 + 2 / ( 10 + 1 / 3 ) == rpnCalculater(result));

		result = rpn_conv("( 6 ) + ( ( 8 ) + ( 9 + 1 ) )");
		REQUIRE(result == "6 8 9 1 + + +");
		REQUIRE(( 6 ) + ( ( 8 ) + ( 9 + 1 ) ) == rpnCalculater(result));

		result = rpn_conv("( 10 + 6 / ( 2 + 4 ) ) + ( 90 / 2 )");
		REQUIRE(result == "10 6 2 4 + / + 90 2 / +");
		REQUIRE(((10 + 6 / ( 2 + 4 ) ) + ( 90 / 2 ))== rpnCalculater(result));

		result = rpn_conv("( ( ( 1 ) * 5 + ( 6 + 6 ) + 5 ) + 6 ) * 6");
		REQUIRE( ((( ( 1 ) * 5 + ( 6 + 6 ) + 5 ) + 6) * 6)== rpnCalculater(result));

	}
}

