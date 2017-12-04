using namespace std;
#include "expertsystem.hpp"
string eraseAllWhiteSpaces(string str);

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Rule{
	public : string rule;
	private: vector<Node> * nodes;
	public : Rule(string rule){
				 this->rule = rule;
				 sanitiseRule();
			 }

	public : Rule(string rule, vector <Node> *nodes){
				 this->rule = rule;
				 this->nodes= nodes;
				 sanitiseRule();
				 initNodes();
			 }
	public : string toString() {
				 return (rule);
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
						 nodes->push_back(Node(c));
					 }
				 }
			 }
	private : int isExistingNode(char c){
				  for (Node node : *nodes)
					  if(node.getSymbol() == c)
						  return (1);
				  return (0);
			  }
};
