#ifndef NODE_H
#define NODE_H
#include "expertsystem.hpp"
#include "Rules.h"

using namespace std;
class Node{
	private : vector<Rule*> listOfIndex;
	private : char symbol;
	private : int status;
	private : string reason;
	public  : Node(char symbol){
				  this->symbol = symbol;
				  this->status = 0;
			  }

	public  : Node(char symbol, string reason){
				  this->symbol = symbol;
          this->reason = reason;
			  }
  public : void addToListOfIndex(int index){
				 listOfIndex.push_back(index);
			 }
	public : char getSymbol(){
				 return (symbol);
			 }
	public : vector<Rule *> getListOfIndex(){
				 return (listOfIndex);
			 }
	public: void setReason(string reason){
				this->reason = reason;
			}
	public: void setStatus(int status){
				this->status = status;
			}
	public : int getStatus(){
				 return (status);
			 }
	public : string getReason(){
				 return (reason);
			 }
  public : void addRule(Rule *rule)
           {
             listOfIndex.push_back(rule);
           }
};

#endif
