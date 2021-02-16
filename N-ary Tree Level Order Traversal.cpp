//QUESTION Link ---> https://leetcode.com/problems/n-ary-tree-level-order-traversal/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
	public:
	    int val = NULL;
	    vector<Node*> children;
	    Node() {}
	    Node(int _val, vector<Node*> _children) {
	        val = _val;
	        children = _children;
	    }
};

class Solution {
	public:
	    vector<vector<int>> levelOrder(Node* root) {
	        if(root == NULL) {
	        	return {}; // Or return vector<vector<int>>();
			}
			vector<vector<int>> res;
			queue<Node*> q;
			q.push(root);
			while(!q.empty()) {
				int size = q.size();
				vector<int> level;
				for(int i=0; i<size; i++) {
					Node *temp = q.front();
					q.pop();
					level.push_back(temp->val);
					vector<Node*>::iterator it;
					for(it = temp->children.begin(); it != temp->children.end(); it++) {
						q.push(*it);
					}
				}
				res.push_back(level);
			}
			return res;
	    }
};

int main(void) {
	return 0;
}
