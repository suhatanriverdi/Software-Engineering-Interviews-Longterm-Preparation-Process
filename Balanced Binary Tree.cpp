//Question Link ---> https://leetcode.com/problems/balanced-binary-tree/
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
	    bool isBalanced(TreeNode* root) {
	    	if(root == NULL) { // OR -> (!root)
	    		return true;
			}

	    	if(abs(height(root->left) - height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right)) {
				return true;	        
			}
			return false;
	    }
		
		int height(TreeNode *head) {
			if(head == NULL) {
				return 0;
			}
			return 1 + max(height(head->left), height(head->right));
		}
};

int main(void) {
//==========> Default Test Case <==========

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(9);
//	n->right = new TreeNode(20);	
//	n->right->left = new TreeNode(15);	
//	n->right->right = new TreeNode(7);


//_-_-_-_-_-_-> Alternative Test Cases <-_-_-_-_-_-_-_
	
//	TreeNode *n = NULL;

//	TreeNode *n = new TreeNode(1);

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(9);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	
//	n->left = new TreeNode(9);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	
//	n->left = new TreeNode(9);
//	n->left->left = new TreeNode(15);	
//	n->right->right = new TreeNode(7);

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
//	n->right->left = new TreeNode(7);
//	n->right->left->left = new TreeNode(7);
//	n->left->right = new TreeNode(15);
//	n->left->right->right = new TreeNode(15);

//_-_-_-_-_-_-> Alternative Test Cases <-_-_-_-_-_-_-_

//	TreeNode *n;
	
//	TreeNode *n = NULL;

//	TreeNode *n = new TreeNode(1);

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(9);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	
//	n->left = new TreeNode(9);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	
//	n->left = new TreeNode(9);
//	n->left->left = new TreeNode(15);	
//	n->right->right = new TreeNode(7);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	
//	n->left = new TreeNode(9);
//	n->left->left = new TreeNode(15);	
//	n->left->right = new TreeNode(15);	
//	n->right->right = new TreeNode(7);
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
	cout << obj.isBalanced(n);	
	return 0;
}
