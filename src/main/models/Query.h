#include "../../../inc/expertsystem.hpp"

string eraseAllWhiteSpaces(string str);
class Query{
	private:string query;
	private:vector<Node*> nodes;

	private : vector<char> querySymbols;
	public : Query()
			 {
			 }
	public : Query(string query, Nodes *allNodes){
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


	public : Node *getNodeByChar(char c)
			 {
				 for (Node *node : nodes)
					 if(node->getSymbol() == c)
						 return (node);
				 return (nullptr);
			 }
	private: void updateQueryNodes(Nodes *allNodes){
				 for (char c : querySymbols){
					 for (Node &node : *allNodes->getNodes()) {
						 if (node.getSymbol() == c)
						 {
							 nodes.push_back(&node);
						 }
					 }
				 }
			 }

};
