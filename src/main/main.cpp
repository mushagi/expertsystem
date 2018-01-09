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
	string ext;
	int eStart;

  if (ac != 2)
    exit_with_error("Usage : expertsystem [filename]");
	fName = av[1];
	eStart = fName.find('.');
	ext = fName.substr(eStart + 1);
	if (ext != "txt")
		exit_with_error("Input must be a *.txt file");
	rFile.open(fName);
	if (!rFile)
    exit_with_error("File does not exist");
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
