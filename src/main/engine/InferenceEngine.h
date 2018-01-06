#include "expertsystem.hpp"

int rpnCalculater(string rpnString);
string rpn_conv(string infixString);
class  InferenceEngine{
  Rules rules;
  Nodes nodes;
  string facts;
  Query query;
  string results;
  public : InferenceEngine(Rules rules, const Nodes nodes, Query query, string facts){
             this->nodes = nodes;
             this->rules = rules;
             this->facts = facts;
             this->query = query;
             initFacts();
           }
  private :void initFacts(){

             for(char &c : facts)
               if (isalpha(c)){
                 Node *node = getNodeBySymbol(c);
                 node->setStatus(1);
               }
           }
		   
  public :Node *getNodeBySymbol(char c)
           {
             for (Node &node : *nodes.getNodes())
               if(node.getSymbol() == c)
                 return(&node);
             return nullptr;
           }

  public : void execute(){
             for (Node *node : query.getNodes())
				 for (int index : node->getListOfIndex())
				 {
					 int res = solve(rules.getRules().at(index));
					 results += node->getSymbol();
					 results += '=';
					 results += res ? "TRUE" : "FALSE";
					 results += '\n';
				 }
           }

  private : int isNodeAFact(Node *node)
            {
              for (char c : facts)
              {
                if (node->getSymbol() == c )
                  return 1;
              }
              return 0;
            }
  private : int solve(Rule rule){
				Nodes tempNodes = nodes;
			   	for (Node *node : rule.getLeftSideNodes())
				{
					if (isNodeAFact(node))
						continue;
				}
				string equation = getEquation(rule.getLeftSide(), tempNodes);
				return rpnCalculater(rpn_conv(equation));
            }
  private : string getEquation(string rule, Nodes tempNodes)
			{
				string temp;

				int count = 1;
				for (char &c : rule)
				{
					if (isalpha(c))
						temp += tempNodes.getNodeByChar(c)->getStatus() + '0';
					else
						temp += convert_to_operator(c);
					if (count != rule.size())
						temp += ' ';
					count++;
				}
				return temp;
			}
  public : char convert_to_operator(char c)
		   {
			   if (c == '+')
				   return ('&');
			   else if (c == '|')
				   return '|';
			   else if (c == '^')
				   return '|';
			   return ' ';
		   }
  public : string getResults()
		   {
			   return results;
		   }

};
