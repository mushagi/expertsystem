#include "../../../inc/expertsystem.hpp"

string eraseAllWhiteSpaces(string str);
class Query{
  private:string query;
  private:vector<Node> nodes;
  private : vector<char> querySymbols;

  public : Query(string query, vector<Node> allNodes){
             this->query = query;
             init(allNodes);
           }
  public: string getQuery()
          {
            return (query);
          }
  public: vector<Node> getNodes(){
            return (nodes);
          }
  private :void init(vector<Node>allNodes)
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

  private: void updateQueryNodes(vector<Node> allNodes){
             int found;

             for (char &c : querySymbols){
               found = 0;
               for(Node node : allNodes)
                 if(node.getSymbol() == c){
                   nodes.push_back(node);
                   found = 1;
                   break;
                 }
               if(!found)
                 nodes.push_back(Node(c, "Initialised as a query node"));
             }
           }
};
