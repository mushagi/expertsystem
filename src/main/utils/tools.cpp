#incude "expertsystem.hpp"
    cout<<endPos<<endl;
#include <algorithm>

string eraseAllWhiteSpaces(string str) {
	str.erase(remove_if(str.begin(), 
			   	str.end(), ::isspace), str.end()); 
	return (str);
}

int string_split(string str, vector<string> *splitArray)
{
  int pos;
  int endPos;
  string tempString;

  if (str.size() == 0)
    return 0;
  pos = 0;
  endPos = str.find(' ', pos);
  while(endPos > 0)
  {
    tempString = str.substr(pos, endPos - pos);
    splitArray->push_back(tempString);
    pos = endPos + 1;
    endPos = str.find(' ', pos);
  }
  tempString = str.substr(pos, str.size());
  splitArray->push_back(tempString);
  return (1);
}
