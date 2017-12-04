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
	Rule rule("A+B+C=>D");

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
		vector<Node> nodes;
		Rule rule1("A+B+C", &nodes);
		REQUIRE(nodes.size() == 3);
	}

}
TEST_CASE("Query class")
{

	SECTION("empty query")
	{
		vector<Node> allNodes1;
		Query query("?     ", allNodes1);
		REQUIRE(query.getNodes().size() == 0);
		REQUIRE(query.getQuery() == "?");
	}

	SECTION("add nodes to query list")
	{
		vector<Node> allNodes;
		Query query1("  ?abc ", allNodes);
		REQUIRE(query1.getQuery() == "?abc");
		REQUIRE(query1.getNodes().size() == 3);

		vector<Node> allNodes2;
		Node nodeTest('w');
		nodeTest.setReason("duh");
		allNodes2.push_back(nodeTest);
		Query query2("  ?wp ", allNodes2);
		REQUIRE(query2.getQuery() == "?wp");
		REQUIRE(query2.getNodes().size() == 2);
		REQUIRE(query2.getNodes().front().getReason() == "duh");
		REQUIRE(query2.getNodes().back().getReason() == "Initialised as a query node");

	}

}

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
	/*
	SECTION("simple inference test"){
		
		vector<Node> nodes;
		vector<Rule> rules;
		Query query("?B", nodes);
		rules.push_back(Rule("A=>B", &nodes));
		string facts = "=A";
		InferenceEngine engine(rules, nodes, &query, facts);
	//	REQUIRE(query.getNodes().front().getStatus() == 0);
	}*/
}
