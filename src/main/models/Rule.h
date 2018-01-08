#ifndef RULE_H
#define RULE_H
#include "expertsystem.hpp"

using namespace std;

string eraseAllWhiteSpaces(string str);
void exit_with_error(string errorString);
int is_op(char c);
class Rule{
	public : string rule;
	private : string rightSide;
	private: string leftSide;
	private: vector<char> leftSideNodes;
	private: Nodes *nodes;
	private : int ruleIndex;
  public : int read;
  private : string what;
	public : Rule(string rule){
				 this->rule = rule;
				 sanitiseAndValidateRule();
				 initSides();
			 }
  public : void setWhat(string what)
           {
             this->what = what;
           }
  public : string getWhat()
           {
             return what;
           }
	public : Rule(string rule, Nodes *nodes){
				 this->rule = rule;
				 this->nodes= nodes;
         this->read = 0;
				 sanitiseAndValidateRule();
				 initNodes();
				 initSides();
			 }
	public : string toString() {
				 return (rule);
			 }
	private : void initSides(){
				  leftSide = rule.substr(0, rule.find('='));
				  rightSide = rule.substr(rule.find('>') + 1);
				  for (Node node : *nodes->getNodes()){
					  for (char c : leftSide)
						  if (c == node.getSymbol())
							  leftSideNodes.push_back(c);
				  }

			  }
	private: void sanitiseAndValidateRule()
			 {
         int equalsFlag = 0;
         int greaterThanFlag = 0;

				 rule = eraseAllWhiteSpaces(rule);
				 getRidOfComments();
         for (char &c : rule)
         {
           if (!isalpha(c) && c != '=' && c != '>' && c != '!' && !is_op(c) && c != ')' && c != '(')
             exit_with_error("The Rule "  + rule + " is invalid symbol");
           if (c == '!' && !isalpha(*(&c + 1)))
             exit_with_error("The Rule "  + rule + " is invalid, no operand after negate sign");
           if (c == '=' && *(&c + 1) != '>')
             exit_with_error("The Rule "  + rule + " is invalid, no > after = ");
           if (c == '=') equalsFlag++;
           if (c == '>')greaterThanFlag++;
         }
         if (equalsFlag != 1)
           exit_with_error("The Rule "  + rule + " has invalid number of equal sign");
         if (greaterThanFlag != 1)
           exit_with_error("The Rule "  + rule + " has invalid number of greater than sign ");
			 }
	private : void getRidOfComments(){
				  rule = rule.substr(0, rule.find('#'));
			  }
	private: void initNodes(){
				 for (char &c : rule){
					 if(isalpha(c) && !isExistingNode(c)){
						 nodes->getNodes()->push_back(Node(c));
					 }
				 }
			 }
	private : int isExistingNode(char c){
				  for (Node &node : *nodes->getNodes())
					  if(node.getSymbol() == c)
						  return (1);
				  return (0);
			  }
	public : string getRule()
			 {
				 return rule;
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
				 setNodesListOfIndex();
			 }
	public : vector <char> getLeftSideNodes()
			 {
				 return leftSideNodes;
			 }
  public : int getRuleIndex()
           {
             return ruleIndex;
           }
  public : void setRead(int isRead)
           {

             this->read = 1;
           }

  public : int getRead()
           {
             return this->read;
           }

};


#endif
