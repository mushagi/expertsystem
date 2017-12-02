#include "expertsystem.hpp"
#include <algorithm>

string eraseAllWhiteSpaces(string str) {
	str.erase(remove_if(str.begin(), 
			   	str.end(), ::isspace), str.end()); 
	return (str);
}
