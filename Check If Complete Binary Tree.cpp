//Question Link ---> https://www.techiedelight.com/check-undirected-graph-contains-cycle-not/
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
		bool isCompleted(TreeNode *root) {
			if(root == NULL || root != NULL && !root->left && !root->right) {
				return true;
			}
			
			if(root->left && !root->right && !(root->left->left || root->left->right)) {
				return true;
			}
			
			if(!root->left && root->right) {
				return false;
			}
			
			if(root->left && root->right && isCompleted(root->left) && isCompleted(root->right)) {
				return true;
			}
			return false;
		}
		
//		int findHeight(TreeNode *root) {
//			if(root == NULL) {
//				return 0;
//			}
//			return 1 + max(findHeight(root->left), findHeight(root->right));
//		}
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

	Solution obj;
	cout << obj.isCompleted(n);	
	return 0;
}
