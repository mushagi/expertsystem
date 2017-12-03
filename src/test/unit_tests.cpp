#include <string>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "expertsystem.hpp"

TEST_CASE( "testing node class" )
{


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

	SECTION("Set initial facts")
	{
			
			node.setReason("Initial fact given");
			node.setStatus(1);
			
			REQUIRE(node.getReason() == "Initial fact given");
			REQUIRE(node.getStatus() == 1);
	}
}


TEST_CASE("testing rules class")
{
	Rule *rule;
	rule = new Rule("A+B+C=>D");

	REQUIRE(rule->toString() == "A+B+C=>D");

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
	vector<Rule> rules;
	vector<Node> nodes;;
/*
	SECTION("One node")
	{
		Node *node= new Node('A');
		node->addToListOfIndex(1);
		nodes->push_back(node);
		rules->push_back(new Rule("A=>A"));
		Query query("A");
		validate_query(nodes, rules, query);

	}
	*/
}
