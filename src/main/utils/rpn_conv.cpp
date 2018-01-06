#include "expertsystem.hpp"
using namespace std;


void printToResult(string str, string *result)
{
	if(result->size() != 0){
		result->append(" ");
	}
	result->append(str);
}

void pop(vector<string > * stack, string *result, bool bracket){
	reverse(stack->begin(), stack->end());
	auto w = stack->begin();
	for (auto r = w, e = stack->end(); r != e; ++r) {
		if (bracket && *w == "(")
		{
			stack->erase(w); 
			break;
		}
		if (*w == "(")
			break;
		printToResult(*w, result);
		stack->erase(w); 
	}
	reverse(stack->begin(), stack->end());

}
int getPreceding(string op)
{
	if(op == "+") return 2;
	if (op == "-") return 2;
	if (op == "*") return 3;
	if (op == "/") return 3;
	if (op == "&") return 4;
	if (op == "|") return 3;
	if (op == "^") return 2;
	if (op == "(") return 1;
	return 0;
}

string rpn_conv(string infixString)
{
	string result;
	int stackPos;
	vector<string> splitArray;
	vector<string> stack;

	stackPos = -1;
	string_split(infixString, &splitArray);

	for(string tempString : splitArray){
		if (isnumber(tempString))
		{
			printToResult(tempString, &result);
		}
		else
		{
			if (tempString == "(")
				stack.push_back(tempString);

			else if(tempString == ")" || (stack.size() >= 1 && getPreceding(tempString) <= getPreceding(stack.back())))
			{
				pop(&stack, &result, tempString == ")");
				if (tempString != ")")
					stack.push_back(tempString);
			}
			else
			{
				stack.push_back(tempString);
			} 
		}
	}
	pop(&stack, &result, false);

	return result;
}
