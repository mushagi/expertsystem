#include "expertsystem.hpp"
using namespace std;

int do_op(int val1, int val2, char op)
{
  if(op == '+')
    return (val1 + val2);
  if(op == '-')
    return (val1 - val2);
  if(op == '*')
    return (val1 * val2);
  if(op == '/')
    return (val1 / val2);
  if(op == '%')
    return (val1 % val2);
  if(op == '^')
    return (val1 ^ val2);
  if(op == '&')
    return (val1 & val2);
  if(op == '|')
    return (val1 | val2);
  return 0;
}

int is_op(char c)
{
  return(c == '+' || c == '-' || c == '/' || c == '*' || c == '^' || c == '%' || c == '^' || c == '&' || c == '|');
}
void push(int *stack, int nbr, int *stackPos)
{
  stack[++*stackPos] = nbr;
}

void pop(int *stack, int *stackPos, char op)
{
  int val1 = stack[*stackPos - 1];
  int val2 = stack[*stackPos];
  int res = do_op(val1, val2, op);
  stack[--*stackPos] = res;
}

int rpnCalculater(string rpnString)
{
  int stack[100];
  int stackPos;
  int result;
  vector<string> splitArray;
  stackPos = -1;
  string_split(rpnString, &splitArray, ' ');
  for(int i = 0; i < 100; i++)
    stack[i] = 0;
  for (string tempString : splitArray)
  {
    if (is_op(tempString[0]) && !isdigit(tempString[1]))
      pop(stack, &stackPos, tempString[0]);
    else
    {
      push(stack, stoi(tempString) , &stackPos);
    }
  }
  return (stack[0]);
}
