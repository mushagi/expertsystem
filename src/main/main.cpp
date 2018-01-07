#include "expertsystem.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main(int ac, char **av)
{
	ifstream rFile;
	string fName;
	string buffer;
	string content;

	fName = av[1];
	rFile.open(fName);
	while (getline(rFile, buffer)){
		buffer = eraseAllWhiteSpaces(buffer);
		if (buffer.size() > 0){
			content += buffer;
			content += '\n';
		}
	}
	run_program(content);
	rFile.close();
	rFile.clear();
	return (0);
}
