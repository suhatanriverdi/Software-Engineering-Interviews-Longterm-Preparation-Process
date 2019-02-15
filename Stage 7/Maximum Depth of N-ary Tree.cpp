//QUESTION Link ---> https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
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
	private:
		int sz=0;
	public:
	    int maxDepth(Node* root) {
	        if(root == NULL) {
	        	return 0;
			}
			queue<Node*> q;
			q.push(root);
			while(!q.empty()) {
				int size = q.size();
				for(int i=0; i<size; i++) {
					Node *temp = q.front();
					q.pop();
					vector<Node*>::iterator it;
					for(it = temp->children.begin(); it != temp->children.end(); it++) {
						q.push(*it);
					}
				}
				sz++;
			}
			return sz;
	    }
};

int main(void) {
	return 0;
}
