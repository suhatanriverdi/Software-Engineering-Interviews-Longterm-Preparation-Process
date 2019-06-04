//QUESTION Link ---> https://leetcode.com/problems/binary-tree-level-order-traversal
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
	    vector<vector<int>> levelOrder(TreeNode* root) {
			vector<vector<int>> res;
	        if(root == NULL) {
	        	return res; // Or return vector<vector<int>>();
			}
			queue<TreeNode*> q;
			q.push(root);
			while(!q.empty()) {
				int size = q.size();
				vector<int> level;
				for(int i=0; i<size; i++) {
					TreeNode *temp = q.front();
					q.pop();
					level.push_back(temp->val);				
					if(temp->left) {
						q.push(temp->left);
					}				
					if(temp->right) {
						q.push(temp->right);
					}
				}
				res.insert(res.begin(),level);
			}
			return res;
	    }
};


int main(void) {
	return 0;
}
