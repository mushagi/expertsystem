#ifndef RULE_H
#define RULE_H
#include "expertsystem.hpp"

using namespace std;

string eraseAllWhiteSpaces(string str);
class Rule{
	public : string rule;
	private : string rightSide;
	private: string leftSide;
	private: Nodes *nodes;
	private : int ruleIndex;
	public : Rule(string rule){
				 this->rule = rule;
				 sanitiseRule();
				 initSides();
			 }

	public : Rule(string rule, Nodes *nodes){
				 this->rule = rule;
				 this->nodes= nodes;
				 sanitiseRule();
				 initNodes();
				 initSides();
				 setNodesListOfIndex();
			 }
	public : string toString() {
				 return (rule);
			 }
	private : void initSides(){
				  leftSide = rule.substr(0, rule.find('='));
				  rightSide = rule.substr(rule.find('>') + 1);
			  }
	private: void sanitiseRule()
			 {
				 rule = eraseAllWhiteSpaces(rule);
				 getRidOfComments();
			 }
	private : void getRidOfComments(){
				  rule = rule.substr(0, rule.find('#'));
			  }
	private: void initNodes(){
				 for (char &c : rule){
					 if(isalpha(c) && !isExistingNode(c)){
						 nodes->getNodes()->push_back(new Node(c));
					 }
				 }
			 }
	private : int isExistingNode(char c){
				  for (Node *node : *nodes->getNodes())
					  if(node->getSymbol() == c)
						  return (1);
				  return (0);
			  }
	public : string getLeftSide(){
				 return (leftSide);
			 }
	public : string getRightSide(){
				 return (rightSide);
			 }
	private: void setNodesListOfIndex()
			 {
				 for (char c : rightSide)
           if (isalpha(c))
             nodes->getNodeByChar(c)->addRule(ruleIndex);
			 }
	public : void setRuleIndex(int ruleIndex)
			 {
				 this->ruleIndex = ruleIndex;
			 }
};

#endif
