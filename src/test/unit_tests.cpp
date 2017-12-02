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
		Query query("?     ");
		REQUIRE(query.getNodes().size() == 0);
		REQUIRE(query.getQuery() == "?");
	}

	SECTION("add nodes to query list")
	{
		Query query1("  ?abc ");
		REQUIRE(query1.getQuery() == "?abc");
		/*
		REQUIRE(query1.getNodes().size() == 3);
		REQUIRE(query1.getNodes().begin()->getSymbol() == 'a');
		REQUIRE((query1.getNodes().begin() + 1)->getSymbol() == 'b');
		REQUIRE((query1.getNodes().begin() + 2)->getSymbol() == 'c');
	*/
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
