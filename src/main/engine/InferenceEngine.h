#include "expertsystem.hpp"

class  InferenceEngine{

	Rules rules;
	Nodes *nodes;
	string facts;

	public : InferenceEngine(Rules rules, Nodes *nodes, 
			Query *query, string facts){
		this->nodes = nodes;
		this->rules = rules;
		this->facts = facts;
		initFacts();
	}
	void initFacts(){
		for(char &c : facts)
			if (isalpha(c))
			{
				Node *node = getNodeBySymbol(c);
				node->setStatus(1);
			}
	}
	Node *getNodeBySymbol(char c)
	{
		for (Node *node : *nodes->getNodes())
			if(node->getSymbol() == c)
				return(node);
		return nullptr;
	}
	void validateQuery(){
	}

};
