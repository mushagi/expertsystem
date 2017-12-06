using namespace std;
#include "expertsystem.hpp"
string eraseAllWhiteSpaces(string str);

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Rule{
	public : string rule;
	private : string rightSide;
	private: string leftSide;
	private: vector<Node*> *nodes;
	public : Rule(string rule){
				 this->rule = rule;
				 sanitiseRule();
				 initSides();
			 }

	public : Rule(string rule, vector <Node*> *nodes){
				 this->rule = rule;
				 this->nodes= nodes;
				 sanitiseRule();
				 initNodes();
				 initSides();
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
						 nodes->push_back(new Node(c));
					 }
				 }
			 }
	private : int isExistingNode(char c){
				  for (Node *node : *nodes)
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
};
