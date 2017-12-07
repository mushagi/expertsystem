#ifndef RULES_H
#define RULES_H
#include "Rule.h"
using namespace std;
#include "expertsystem.hpp"

class Rules{

	vector<Rule> rules;

	public : Rules(){
			 }
	public : void add(Rule rule)
			 {
				 rule.setRuleIndex(rules.size());
				 rules.push_back(rule);
			 }
	public : int size()
			 {
				 return(rules.size());
			 }
};

#endif

