//Question Link ---> https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 
 
class Solution {
	public:
		int maxDepth(TreeNode* root) {
			if(root == NULL) {
				return 0;
			}
			return 1 + max(maxDepth(root->left),maxDepth(root->right));
		}
};

int main(void) {
	TreeNode *n = new TreeNode(3);
	n->left = new TreeNode(9);
	n->right = new TreeNode(20);	
	n->right->left = new TreeNode(15);	
	n->right->right = new TreeNode(7);
	Solution obj;
	cout << obj.maxDepth(n);	
	return 0;
}
