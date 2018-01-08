#include "expertsystem.hpp"

int rpnCalculater(string rpnString);
string rpn_conv(string infixString);
class  InferenceEngine{
  Rules rules;
  Nodes nodes;
  string facts;
  Query query;
  string results;

  public : InferenceEngine(Rules rules, const Nodes nodes, Query query, string facts){
             this->nodes = nodes;
             this->rules = rules;
             this->facts = facts;
             this->query = query;
             initFacts();
           }
  private :void initFacts(){

             for(char &c : facts)
               if (isalpha(c)){
                 Node *node = getNodeBySymbol(c);
                 node->setStatus(1);
               }
           }

  public :Node *getNodeBySymbol(char c)
          {
            for (Node &node : *nodes.getNodes())
              if(node.getSymbol() == c)
                return(&node);
            return nullptr;
          }

  public : void execute(){
             cout<<"=========ES Starting to solve==========\n"<<endl;
             for (Node *node : query.getNodes())
             {
               cout<<"======solving query(" << node->getSymbol()<<") ======"<<endl;
               if (isNodeAFact(node))
               {
                 cout<<"Node is true"<<endl;
                 results += node->getSymbol();
                 results += '=';
                 results += "TRUE";
                 results += '\n';
               }
               else 
               {
                 int res = 0;
                 for (int index : node->getListOfIndex())
                 {
                   vector <int> readRules;
                   res = solve(rules.getRules().at(index), index, readRules) || res;
                 }
                 results += node->getSymbol();
                 results += '=';
                 results += res ? "TRUE" : "FALSE";
                 results += '\n';
               }
             }
             cout<<"\n=========ES Done=========="<<endl;
           }

  private : int isNodeAFact(Node *node)
            {
              for (char c : facts)
                if (node->getSymbol() == c )
                  return 1;
              return 0;
            }
  public : int isRuleRead(int index, vector<int> readRules)
           {
             for (int i : readRules)
               if (index == i)
                 return 1;
             return 0;
           }
  private : int solve(Rule rule, int ruleIndex, vector<int> readRules){
              Nodes tempNodes = nodes;
              if (!isRuleRead(ruleIndex, readRules))
              { 
                readRules.push_back(rule.getRuleIndex());
                cout<<rule.getRule() <<" read " <<rules.getRules().at(ruleIndex).getRead() <<endl;
                for (char c : rule.getLeftSideNodes())
                {
                  cout<<"Solving the node : "<< c<<endl;
                  Node *node = tempNodes.getNodeByChar(c);
                  if (isNodeAFact(node))
                  {
                    cout << c << " is a fact"<<endl;
                    continue;
                  }
                  else
                    for (int index : node->getListOfIndex())
                    {
                      cout<<"The node " << c << " is going to recurssion|"<<" rule = " <<rules.getRules().at(index).getRule()<<endl;
                      node->setStatus(solve(rules.getRules().at(index), index, readRules));

                    }
                }
              }
              else cout <<"The node was going to an infinite loop, therefore, it is set as false"<<endl;

              string equation = getEquation(rule.getLeftSide(), tempNodes);
              cout<<rule.getLeftSide()<<" becomes ["<<equation<<"]"<<endl;
              return rpnCalculater(rpn_conv(equation));
            }
  private : string getEquation(string rule, Nodes tempNodes)
            {
              string temp;
              bool negate = false;
              int count = 1;
              for (char &c : rule)
              {
                if (c == '!')
                  negate = true;
                else
                {
                  if (isalpha(c))
                    if (negate){
                      temp += !tempNodes.getNodeByChar(c)->getStatus() + '0';
                      negate = false;
                    }
                    else temp += tempNodes.getNodeByChar(c)->getStatus() + '0';

                  else if (c != ' ')
                    temp += convert_to_operator(c);
                  if (count != rule.size())
                    temp += ' ';
                }
                count++;
              }
              return temp;
            }
  public : char convert_to_operator(char c)
           {
             if (c == '+')
               return ('&');
             else if (c == '|')
               return '|';
             else if (c == '^')
               return '^';
             return c;
           }
  public : string getResults()
           {
             return results;
           }
};
