#include "expertsystem.hpp"
using namespace std;
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
			*query = temp;
	}

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
	Query query(queryString, &nodes);
	InferenceEngine engine(rules, nodes, query, facts);
	engine.execute();
	cout<<endl<<engine.getResults()<<endl;
}
