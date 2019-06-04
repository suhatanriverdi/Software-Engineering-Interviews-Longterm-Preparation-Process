//QUESTION Link ---> https://leetcode.com/problems/n-ary-tree-preorder-traversal
#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
//class Node {
//public:
//    int val;
//    vector<Node*> children;
//
//    Node() {}
//
//    Node(int _val, vector<Node*> _children) {
//        val = _val;
//        children = _children;
//    }
//};

class Solution {
	public:
	    vector<int> preorder(Node *root) {
			vector<int> res;
			if(root == NULL) {
				return res;
			}
			helperDFS(root, res);
			return res;
	    }
	    
	    void helperDFS(Node *root, vector<int> &path) {
	    	path.push_back(root->val);
	    	for(auto i : root->children) {
	    		helperDFS(i, path);
			}
		}
};

int main(void) {
	Solution obj;
	return 0;
}
