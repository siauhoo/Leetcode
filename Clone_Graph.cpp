#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
using namespace std;
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
	UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
		if(node == NULL) return NULL;
		UndirectedGraphNode* pCopiedGraph = NULL;
		map<UndirectedGraphNode *, UndirectedGraphNode *> relation;
		queue<UndirectedGraphNode *> Q;

		UndirectedGraphNode *new_node = new UndirectedGraphNode(node->label);
		pCopiedGraph = new_node;
		relation.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(node, new_node));
		Q.push(node);

		vector<UndirectedGraphNode *>::iterator v_it;
		map<UndirectedGraphNode*, UndirectedGraphNode*>::iterator g_it;

		while(!Q.empty())
		{
			UndirectedGraphNode* pCur;
			pCur = Q.front();
			Q.pop();
			for(v_it = pCur->neighbors.begin(); v_it != pCur->neighbors.end(); v_it++)
			{
				g_it = relation.find(*v_it);
				if(g_it == relation.end())
				{
					UndirectedGraphNode *new_node = new UndirectedGraphNode((*v_it)->label);
					relation.insert(pair<UndirectedGraphNode*, UndirectedGraphNode*>(*v_it, new_node));
					Q.push(*v_it);
				}
			}
		}
		for(g_it = relation.begin(); g_it != relation.end(); g_it++)
		{
			UndirectedGraphNode *first = (g_it)->first;
			UndirectedGraphNode *second = (g_it)->second;
			for(v_it = (first->neighbors).begin(); v_it != (first->neighbors).end(); v_it++)
			{
				(second->neighbors).push_back((relation.find(*v_it))->second);
			}
		}
		return pCopiedGraph;
	}
};
int main()
{
}
