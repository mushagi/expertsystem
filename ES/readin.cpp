#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

void vector_rule(string rule, vector<string> vRule);
int main()
{
	ifstream rFile;
	string fName;
	string content;
	string rule;
	string tLine;
	string qLine;
	int i = 0;

	cout << "Please enter file name or type E to exit: ";
	cin >> fName;	
	if (fName != "E")
	{	rFile.open(fName);
		if (rFile.fail())
		{
			cout << "Error opening and reading the file named \"" 
				<< fName <<"\"!\nPlease make sure the file does exits!";
		}
		else
		{
			cout << "\nYou are now testing file named "<< fName 
				<< "\nThese are the rules:\n\n";
			vector <string> vRule;
			while (getline(rFile, content))
			{
				if (isalpha(content[0]))
				{
					rule = content;
					vRule.push_back(rule);	
					vector_rule(rule, vRule);
				}
				if (content[0] == '?')
					qLine = content.substr(1, content.find('\n'));
				if (content[0] == '=')
				{
					tLine = content.substr(0, content.find(','));
					cout << "The following are truth set number: "<< ++i <<endl;
					cout << tLine << endl;
				}
			}
			cout << "\nWe are now testing for the following vaiables: " << qLine 
				<<" with the above given facts and rules!"<< endl;
		}
		rFile.close();
		rFile.clear();
	}
	cout << "\nGood bye!!\n";
	return (0);
}

void vector_rule(string rule,vector<string> vRule)
{
	//vRule.push_back(rule);
	unsigned int vec_num = vRule.size();
	if (vRule.empty())
		cout << "\nThere are no rules passed in!!!\n";
	else
		for (unsigned int i = 0; i < vRule.size(); i++)
			cout << vRule[i] << endl;
	cout << "There are "<< vRule.size() << " node\\s in the vectors!\n";
}
