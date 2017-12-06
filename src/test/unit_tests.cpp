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


TEST_CASE("testing rules class")
{
	vector <Node*> nodes;
	Rule rule("A+B+C=>D", &nodes);

	REQUIRE(rule.toString() == "A+B+C=>D");
	SECTION("Complex rule")
	{
		Rule ruleComplex(" A + B + D             => G ");
		REQUIRE(ruleComplex.toString() == "A+B+D=>G");
	}
	SECTION("get rid of the comments ")
	{
		Rule ruleComplex2(" A + B + D             => G        # HEllo there stranger");
		REQUIRE(ruleComplex2.toString() == "A+B+D=>G");
	}

	SECTION("add nodes while reading a rule")
	{
		vector<Node*> nodes;
		Rule rule1("A+B+C=>N", &nodes);
		REQUIRE(nodes.size() == 4);
	}
	SECTION("Seperate sides"){
		Rule rule("A+B+C=>C");
		REQUIRE(rule.getLeftSide() == "A+B+C");
		REQUIRE(rule.getRightSide() == "C");
	}

}
TEST_CASE("Query class")
{

	
	SECTION("empty query")
	{
		vector<Node*> nodes;
		vector<Rule> rules;
		rules.push_back(Rule("A+B+C=>D", &nodes));
		Query query("?     ", &nodes);
		REQUIRE(query.getNodes().size() == 0);
		REQUIRE(query.getQuery() == "?");
	}
	
	SECTION("add nodes to query list")
	{
		vector<Node*>nodes;

		vector<Rule> rules;
		rules.push_back(Rule("A+B+C=>D", &nodes));
		Query query("?AB", &nodes);
		REQUIRE(query.getQuery() == "?AB");
		REQUIRE(query.getNodes().front()->getSymbol() == 'A');
		REQUIRE(query.getNodes().front()->getSymbol() == nodes.front()->getSymbol());
		REQUIRE(query.getNodes().front() == nodes.front());
		REQUIRE(query.getNodes().front()->getReason() == "changed");
		REQUIRE(nodes.front()->getReason() == "changed");
	}	

}
/*
TEST_CASE("testing inference engine")
{
	SECTION("testing initial updated facts"){
		
		vector<Node> nodes;
		vector<Rule> rules;
		Query query("?B", nodes);
		rules.push_back(Rule("A=>B", &nodes));
		string facts = "=A";
		InferenceEngine engine(rules, &nodes, &query, facts);
		REQUIRE(nodes.front().getSymbol() == 'A');
		REQUIRE(nodes.front().getStatus() == 1);
		REQUIRE(nodes.back().getSymbol() == 'B');
		REQUIRE(nodes.back().getStatus() == 0);
	}
	SECTION("simple inference test"){
		
		vector<Node> nodes;
		vector<Rule> rules;
		Query query("?B", nodes);
		rules.push_back(Rule("A=>B", &nodes));
		string facts = "=A";
		InferenceEngine engine(rules, nodes, &query, facts);
	//	REQUIRE(query.getNodes().front().getStatus() == 0);
	}

}

*/
