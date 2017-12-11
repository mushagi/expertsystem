#include "expertsystem.hpp"
using namespace std;


void printToResult(string str, string *result)
{
  result->append(str);
  result->append(" ");
}

void print_remaining_ops(vector<string> stack, string *result)
{
  for (string tempString : stack)
  {
    if(tempString == stack.back())
      result->append(tempString);
    else
      printToResult(tempString, result);
  }
}

int getPreceding(string op)
{
  if(op == "+") return 2;
  if (op == "-") return 2;
  if (op == "*") return 3;
  if (op == "/") return 3;
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
      if(stack.size() > 1 && getPreceding(tempString) )
      stack.push_back(tempString);
    }
  }
  print_remaining_ops(stack, &result);

  return result;
}
