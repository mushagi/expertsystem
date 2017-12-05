#include "../../../inc/expertsystem.hpp"

string eraseAllWhiteSpaces(string str);
class Query{
	private:string query;
	private:vector<Node*> nodes;
	private : vector<char> querySymbols;

	public : Query(string query, vector<Node*> *allNodes){
				 this->query = query;
				 init(allNodes);
			 }
	public: string getQuery()
			{
				return (query);
			}
	public: vector<Node*> getNodes(){
				return (nodes);
			}
	private :void init(vector<Node*> *allNodes)
			 {
				 query = eraseAllWhiteSpaces(query);
				 if (!isValidQuery(query))
					 throw invalid_argument(
							 "invalid query" );
				 updateQuerySymbols();
				 updateQueryNodes(allNodes);
			 }
	private: int isValidQuery(string query){
				 return (query[0] == '?');
			 }

	private : void updateQuerySymbols(){
				  for(char &c : query){
					  if(c != '?'){
						  querySymbols.push_back(c);
					  }
				  }
			  }

	private: void updateQueryNodes(vector <Node*> *allNodes){
				 nodes.push_back(allNodes->front());
				 allNodes->front()->setReason("changed");
			 }
};
