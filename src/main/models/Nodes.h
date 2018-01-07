#ifndef NO_H
#define NO_H
#include "expertsystem.hpp"

using namespace std;
class Nodes{
	private : vector<Node> nodes;
	public : void add(Node node)
			 {
				 nodes.push_back(node);

			 }
	public : int size()
			 {
				 return (nodes.size());
			 }

	public : Node *getNodeByChar(char c)
			 {
				 for (Node &node : nodes)
					 if(node.getSymbol() == c)
						 return (&node);
				 return (nullptr);
			 }

	public : vector<Node> *getNodes()
			 {
				 return (&nodes);
			 }
};

#endif
