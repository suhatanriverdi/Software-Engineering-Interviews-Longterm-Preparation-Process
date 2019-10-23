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
		vector<int> r1, r2;
	    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
	        savePaths_1(root1);
	        savePaths_2(root2);
	        for(int i=0; i<min(r2.size(), r1.size()); i++){
	        	if(r1[i] != r2[i]) {
	        		return false;	
				}
			}
			return true;
	    }
	    void savePaths_1(TreeNode *root) {
	    	if(root->left == NULL && root->right == NULL) {
	    		r1.push_back(root->val);
			}
			if(root->left != NULL) {
				savePaths_1(root->left);
			}
			if(root->right != NULL) {
				savePaths_1(root->right);
			}
		}
		
		void savePaths_2(TreeNode *root) {
	    	if(root->left == NULL && root->right == NULL) {
	    		r2.push_back(root->val);
			}
			if(root->left != NULL) {
				savePaths_2(root->left);
			}
			if(root->right != NULL) {
				savePaths_2(root->right);
			}
		}
};

int main(void) {
	TreeNode *n = new TreeNode(3);
	n->left = new TreeNode(9);
	n->right = new TreeNode(20);	
	n->right->left = new TreeNode(15);	
	n->right->right = new TreeNode(7);
	
	TreeNode *m = new TreeNode(3);
	m->left = new TreeNode(9);
	m->right = new TreeNode(20);	
	m->right->left = new TreeNode(15);	
	m->right->right = new TreeNode(7);
	
	Solution obj;
	cout << obj.leafSimilar(n, m);	
	return 0;
}
