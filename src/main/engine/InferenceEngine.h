#include "expertsystem.hpp"

class  InferenceEngine{

  Rules rules;
  Nodes nodes;
  string facts;
  Query query;
  public : InferenceEngine(Rules rules, Nodes nodes, Query query, string facts){
             this->nodes = nodes;
             this->rules = rules;
             this->facts = facts;
             this->query = query;
             initFacts();
           }
  private :void initFacts(){
             for(char &c : facts)
               if (isalpha(c))
               {
                 Node *node = getNodeBySymbol(c);
                 node->setStatus(1);
               }
           }
  private :Node *getNodeBySymbol(char c)
           {
             for (Node *node : *nodes.getNodes())
               if(node->getSymbol() == c)
                 return(node);
             return nullptr;
           }
  public : void execute(){
			   cout<<"about to execute"<<endl;
			   Nodes queryNodes = query.getNodes();

			   for (Node *node : *queryNodes.getNodes())
			   {
				   int index = node->getListOfIndex().front();
				   solve(rules.getRules().at(index));
			   }
	
           }

  private : int solve(Rule rule)
			{
				return 0;
			}

};
