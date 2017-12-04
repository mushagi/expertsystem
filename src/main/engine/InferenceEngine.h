#include "expertsystem.hpp"

class  InferenceEngine{

	vector<Rule> rules;
	vector<Node> *nodes;
	string facts;

	public : InferenceEngine(vector<Rule> rules, vector<Node> *nodes, 
			Query *query, string facts){
		this->nodes = nodes;
		this->rules = rules;
		this->facts = facts;
		initFacts();
	}
	void initFacts(){
		for(char &c : facts)
		{
			if (isalpha(c))
			{
				Node *node = getNodeBySymbol(c);
				node->setStatus(1);
			}
		}
	}
	Node *getNodeBySymbol(char c)
	{
		for (Node &node : *nodes)
			if(node.getSymbol() == c)
				return(&node);
		return nullptr;
	}
	void validateQuery(){
	}

};
