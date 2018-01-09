#include "expertsystem.hpp"
using namespace std;

void checkQueries(Nodes nodes,string  query)
{
	bool match = false;
	int count = 0;
	for (char c : query)
	{
		if (count == 0)
		{
			count++;
			continue;
		}
		for (Node node : *nodes.getNodes())
			if (node.getSymbol() == c)
			{
				match = true;
				break;
			}
		if (!match)
			exit_with_error("Undefined query");
	}
}

void validateInput(string *input)
{
	for (char c : *input)
		if (!isalpha(c))
			exit_with_error(": input is not alphabet or is lower case.");
		else if (islower(c))
			exit_with_error(": input is not alphabet or is lower case.");
}

void validateQuery(string *input)
{
	int count = 0;

	for (char c : *input)
	{
		if (count == 0)
		{
			count++;
			continue;
		}
		if (!isalpha(c))
		{
			cout<<"c = " << c<<endl;
			exit_with_error(": input is not alphabet or is lower case. Query");
	
		}
		else if (islower(c))
			exit_with_error(": input is not alphabet or is lower case. Query");
	}
}
void init(string content, Rules *rules, Nodes *nodes, string  *query, string *facts)
{
	vector<string> stringArray;
	string_split(content, &stringArray, '\n');
	bool factFound = false;
	for (string temp : stringArray)
	{
		if(isalpha(temp[0]) || temp[0] == '!' || temp[0] == '(')
			rules->add(Rule(temp, nodes));
		else if (temp[0] == '=')
		{
			factFound = true;
			*facts = &temp[1];
		}
		else if (temp[0] == '?')
		{
			*query = temp;
		}
	}
	validateInput(facts);
	validateQuery(query);
	if (!factFound)
		exit_with_error("there are no facts given");
}

void run_program(string content)
{
	Nodes nodes;
	Rules rules;
	string queryString; 
	string facts;
	init(content, &rules, &nodes, &queryString, &facts);
	checkQueries(nodes, queryString);
	Query query(queryString, &nodes);

	InferenceEngine engine(rules, nodes, query, facts);
	engine.execute();
	cout<<endl<<engine.getResults()<<endl;
}
