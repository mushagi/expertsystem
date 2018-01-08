#include "expertsystem.hpp"
#include <algorithm>
#include <unistd.h>
using namespace std;

string eraseAllWhiteSpaces(string str) {
	str.erase(remove_if(str.begin(), 
			   	str.end(), ::isspace), str.end()); 
	return (str);
}

int string_split(string str, vector<string> *splitArray, char c)
{
  int pos;
  int endPos;
  string tempString;

  if (str.size() == 0)
    return 0;
  pos = 0;
  endPos = str.find(c, pos);
  while(endPos > 0)
  {
    tempString = str.substr(pos, endPos - pos);
    splitArray->push_back(tempString);
    pos = endPos + 1;
    endPos = str.find(c, pos);
  }
  tempString = str.substr(pos, str.size());
  splitArray->push_back(tempString);
  return (1);
}

int isnumber(string str)
{
  const char * cstr = str.c_str();

  if (*cstr == '-')
    cstr++;
  if (!*cstr)
    return 0;
  while(*cstr)
  {
    if(!isdigit(*cstr))
      return 0;
    cstr++;
  }

  return 1;
}

int is_op(char c)
{
    return(c == '+' || c == '-' || c == '/' || c == '*' || c == '^' || c == '%' || c == '^' || c == '&' || c == '|');
}

int		brackets(char *s)
{
	char	br[128];
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (s[++i])
	{
		(s[i] == '(') ? br[++j] = '(' : 0;
		(s[i] == '{') ? br[++j] = '{' : 0;
		(s[i] == '[') ? br[++j] = '[' : 0;
		if (s[i] == ')')
		{
			if (j < 0)
				break ;
			if (br[j--] == '(');
			else
				break ;
		}
		if (s[i] == '}')
		{
			if (j < 0)
				break ;
			if (br[j--] == '{');
			else
				break ;
		}
		if (s[i] == ']')
		{
			if (j < 0)
				break ;
			if (br[j--] == '[');
			else
				break ;
		}
	}
	return (j == -1 && s[i] == '\0') ? 1 : 0;
}
