//Question Link ---> https://leetcode.com/problems/increasing-order-search-tree/
#include <iostream>
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
		TreeNode *head = nullptr;
		TreeNode *walk = head;
	    TreeNode *increasingBST(TreeNode *root) {
	        if(root == nullptr) {
	            return nullptr;
	        }
			reArrange(root);
			inOrderPrint(head);
			return head;
	    }
	    
	    void reArrange(TreeNode *root) {
	    	if(root == nullptr) {
	            return;
	        }
		    reArrange(root->left);
	        insertBT(root->val); // Rearrange New Binary Tree
		    reArrange(root->right);
		}
		
		void insertBT(int n) {
			//cout << node->val << " ";
			if(head == nullptr) {
				head = new TreeNode(n);
				head->right = head->left = NULL;
				walk = head;
			}
			else {
				walk->right = new TreeNode(n);
				walk = walk->right;
			}
		}
		
		void inOrderPrint(TreeNode *root) {
	    	if(root == nullptr) {
	            return;
	        }
		    inOrderPrint(root->left);
	        cout << root->val << " ";
		    inOrderPrint(root->right);
		}
};

int main(void) {
	TreeNode *n = new TreeNode(5);
	n->left = new TreeNode(3);
	n->right = new TreeNode(6);		
	n->right->right = new TreeNode(8);
	n->right->right->right = new TreeNode(9);
	n->right->right->left = new TreeNode(7);
	n->left->left = new TreeNode(2);
	n->left->left->left = new TreeNode(1);
	n->left->right = new TreeNode(4);
	Solution obj;
	obj.increasingBST(n);
	return 0;
}
