#include "expertsystem.hpp"
string eraseAllWhiteSpaces(string str);
class Query{
	private:string query;
	private:vector<Node> nodes;
	public : Query(string query){
				 this->query = query;
				 init();
			 }
	public: string getQuery()
			{
				return (query);
			}
	public: vector<Node> getNodes(){
				return (nodes);
			}
	private :void init()
			 {
				 query = eraseAllWhiteSpaces(query);
				 if (!isValidQuery(query))
					 throw invalid_argument(
							 "invalid query" );
			 }
	private: int isValidQuery(string query){
				 return (query[0] == '?');
			 }
};
