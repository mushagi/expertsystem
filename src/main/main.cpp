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

  if (ac != 2)
    exit_with_error("Usage : expertsystem [filename]");
	fName = av[1];
	rFile.open(fName);
	if (!rFile)
    exit_with_error("File does not exit");
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
