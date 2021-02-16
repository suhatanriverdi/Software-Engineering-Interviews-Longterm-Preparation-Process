//Question Link ---> https://leetcode.com/problems/symmetric-tree/description/
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
	public:
	    bool isSymmetric(TreeNode* root) {
	    	return isMirror(root, root);
	    }
	    
	    bool isMirror(TreeNode* h1, TreeNode* h2) {
	    	if(h1 == NULL && h2 == NULL) {
	    		return true;
			}
			
			if(h1 == NULL || h2 == NULL) {
	    		return false;
			}
			
			if(h1->val == h2->val) {
				return (isMirror(h1->left, h2->right) && isMirror(h1->right, h2->left));
			}
			return false;
		}
};

int main(void) {
//==========> Default Test Case <==========

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(2);
//	n->right = new TreeNode(2);	
//	n->right->left = new TreeNode(4);	
//	n->right->right = new TreeNode(3);
//	n->left->left = new TreeNode(3);	
//	n->left->right = new TreeNode(4);
	
//_-_-_-_-_-_-> Alternative Test Cases <-_-_-_-_-_-_-_

//	TreeNode *n;
	
//	TreeNode *n = NULL;

//	TreeNode *n = new TreeNode(1);

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(9);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(2);	
//	n->left = new TreeNode(2);

//	TreeNode *n = new TreeNode(0);
//	n->right = new TreeNode(2);	
//	n->left = new TreeNode(2);

//	TreeNode *n = new TreeNode(-1);
//	n->right = new TreeNode(2);	
//	n->left = new TreeNode(2);

//	TreeNode *n = new TreeNode(0);
//	n->right = new TreeNode(99);	
//	n->left = new TreeNode(5);

//	TreeNode *n = new TreeNode(0);
//	n->right = new TreeNode(5);	
//	n->left = new TreeNode(99);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(1);	
//	n->left = new TreeNode(1);
//	n->left->left = new TreeNode(2);	
//	n->right->right = new TreeNode(2);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(2);	
//	n->left = new TreeNode(2);
//	n->left->left = new TreeNode(1);	
//	n->left->right = new TreeNode(15);	
//	n->right->right = new TreeNode(1);
//	n->right->left = new TreeNode(15);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);		
//	n->right->right = new TreeNode(7);
//	n->right->right->right = new TreeNode(7);

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(9);
//	n->left->left = new TreeNode(15);
//	n->left->left->left = new TreeNode(15);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	
//	n->right->left = new TreeNode(15);
//	n->right->left->left = new TreeNode(15);

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(20);	
//	n->left->right = new TreeNode(15);
//	n->left->right->right = new TreeNode(15);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	
//	n->left = new TreeNode(9);
//	n->right->left = new TreeNode(15);	
//	n->left->right = new TreeNode(7);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);		
//	n->right->left = new TreeNode(7);
//	n->right->left->left = new TreeNode(7);

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(9);
//	n->left->right = new TreeNode(15);
//	n->left->right->right = new TreeNode(15);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);		
//	n->left = new TreeNode(9);
//	n->right->right = new TreeNode(7);
//	n->right->right->right = new TreeNode(7);
//	n->left->right = new TreeNode(15);
//	n->left->right->right = new TreeNode(15);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);		
//	n->left = new TreeNode(9);
//	n->right->left = new TreeNode(7);
//	n->right->left->left = new TreeNode(7);
//	n->left->left = new TreeNode(15);
//	n->left->left->left = new TreeNode(15);

	Solution obj;
	cout << obj.isSymmetric(n);	
	return 0;
}
