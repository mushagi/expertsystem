#include "../../../inc/expertsystem.hpp"

string eraseAllWhiteSpaces(string str);
class Query{
	private:string query;
	private:Nodes nodes;

	private : vector<char> querySymbols;
	public : Query(string query, Nodes *allNodes){
				 this->query = query;
				 init(allNodes);
			 }
	public: string getQuery()
			{
				return (query);
			}
	public: Nodes getNodes(){
				return (nodes);
			}
	private :void init(Nodes *allNodes)
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

	private: void updateQueryNodes(Nodes *allNodes){
				 for (char c : querySymbols){
					 for (Node *node : *allNodes->getNodes()) {
						 if (node->getSymbol() == c)
						 {
							 nodes.add(node);
						 }
					 }
				 }
			 }
};
