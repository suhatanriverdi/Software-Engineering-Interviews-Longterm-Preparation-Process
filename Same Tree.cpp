//Question Link ---> https://leetcode.com/problems/same-tree/description/
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
	    bool isSameTree(TreeNode* p, TreeNode* q) {
	    	if(p == NULL && q == NULL) {
	    		return true;
			}
			
			if(p == NULL && q != NULL || p != NULL && q == NULL) {
				return false;	
			}
			
			if(p->val == q->val) {
				return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
			}
			return false;
	    }
};

int main(void) {
	TreeNode *n = new TreeNode(1);
	n->left = new TreeNode(2);
	n->right = new TreeNode(3);	
	n->right->left = new TreeNode(6);	
	n->right->right = new TreeNode(7);
	
	TreeNode *m = new TreeNode(1);
	m->left = new TreeNode(2);
	m->right = new TreeNode(3);	
	m->right->left = new TreeNode(6);	
	m->right->right = new TreeNode(7);
	
//==========> Default Test Case <==========
/*
	TreeNode *n = new TreeNode(1);
	n->left = new TreeNode(2);
	n->right = new TreeNode(3);	
	n->right->left = new TreeNode(6);	
	n->right->right = new TreeNode(7);
	
	TreeNode *m = new TreeNode(1);
	m->left = new TreeNode(2);
	m->right = new TreeNode(3);	
	m->right->left = new TreeNode(6);	
	m->right->right = new TreeNode(7);
*/
	
//_-_-_-_-_-_-> Alternative Test Cases <-_-_-_-_-_-_-_

//	TreeNode *n;
//	TreeNode *m;
	
//	TreeNode *n = NULL;
//	TreeNode *m = NULL;

//	TreeNode *n = NULL;
//	TreeNode *m = new TreeNode(1);

//	TreeNode *m = NULL;
//	TreeNode *n = new TreeNode(1);

//	TreeNode *n = new TreeNode(1);
//	TreeNode *m = new TreeNode(1);

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(9);
//	TreeNode *m = new TreeNode(1);
//	m->left = new TreeNode(9);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);
//	TreeNode *m = new TreeNode(1);
//	m->right = new TreeNode(20);	

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	
//	n->left = new TreeNode(9);
//	TreeNode *m = new TreeNode(1);
//	m->right = new TreeNode(20);	
//	m->left = new TreeNode(9);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	
//	n->left = new TreeNode(9);
//	n->left->left = new TreeNode(15);	
//	n->right->right = new TreeNode(7);
//	TreeNode *m = new TreeNode(1);
//	m->right = new TreeNode(20);	
//	m->left = new TreeNode(9);
//	m->left->left = new TreeNode(15);	
//	m->right->right = new TreeNode(7);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	
//	n->left = new TreeNode(9);
//	n->left->left = new TreeNode(15);	
//	n->left->right = new TreeNode(15);	
//	n->right->right = new TreeNode(7);
//	n->right->left = new TreeNode(15);
//	TreeNode *m = new TreeNode(1);
//	m->right = new TreeNode(20);	
//	m->left = new TreeNode(9);
//	m->left->left = new TreeNode(15);	
//	m->left->right = new TreeNode(15);	
//	m->right->right = new TreeNode(7);
//	m->right->left = new TreeNode(15);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);		
//	n->right->right = new TreeNode(7);
//	n->right->right->right = new TreeNode(7);
//	TreeNode *m = new TreeNode(1);
//	m->right = new TreeNode(20);		
//	m->right->right = new TreeNode(7);
//	m->right->right->right = new TreeNode(7);

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(9);
//	n->left->left = new TreeNode(15);
//	n->left->left->left = new TreeNode(15);
//	TreeNode *m = new TreeNode(1);
//	m->left = new TreeNode(9);
//	m->left->left = new TreeNode(15);
//	m->left->left->left = new TreeNode(15);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	
//	n->right->left = new TreeNode(15);
//	n->right->left->left = new TreeNode(15);
//	TreeNode *m = new TreeNode(1);
//	m->right = new TreeNode(20);	
//	m->right->left = new TreeNode(15);
//	m->right->left->left = new TreeNode(15);

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(20);	
//	n->left->right = new TreeNode(15);
//	n->left->right->right = new TreeNode(15);
//	TreeNode *m = new TreeNode(1);
//	m->left = new TreeNode(20);	
//	m->left->right = new TreeNode(15);
//	m->left->right->right = new TreeNode(15);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);	
//	n->left = new TreeNode(9);
//	n->right->left = new TreeNode(15);	
//	n->left->right = new TreeNode(7);
//	TreeNode *m = new TreeNode(1);
//	m->right = new TreeNode(20);	
//	m->left = new TreeNode(9);
//	m->right->left = new TreeNode(15);	
//	m->left->right = new TreeNode(7);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);		
//	n->right->left = new TreeNode(7);
//	n->right->left->left = new TreeNode(7);
//	TreeNode *m = new TreeNode(1);
//	m->right = new TreeNode(20);		
//	m->right->left = new TreeNode(7);
//	m->right->left->left = new TreeNode(7);

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(9);
//	n->left->right = new TreeNode(15);
//	n->left->right->right = new TreeNode(15);
//	TreeNode *m = new TreeNode(1);
//	m->left = new TreeNode(9);
//	m->left->right = new TreeNode(15);
//	m->left->right->right = new TreeNode(15);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);		
//	n->left = new TreeNode(9);
//	n->right->right = new TreeNode(7);
//	n->right->right->right = new TreeNode(7);
//	n->left->right = new TreeNode(15);
//	n->left->right->right = new TreeNode(15);
//	TreeNode *m = new TreeNode(1);
//	m->right = new TreeNode(20);		
//	m->left = new TreeNode(9);
//	m->right->right = new TreeNode(7);
//	m->right->right->right = new TreeNode(7);
//	m->left->right = new TreeNode(15);
//	m->left->right->right = new TreeNode(15);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);		
//	n->left = new TreeNode(9);
//	n->right->left = new TreeNode(7);
//	n->right->left->left = new TreeNode(7);
//	n->left->left = new TreeNode(15);
//	n->left->left->left = new TreeNode(15);
//	TreeNode *m = new TreeNode(1);
//	m->right = new TreeNode(20);		
//	m->left = new TreeNode(9);
//	m->right->left = new TreeNode(7);
//	m->right->left->left = new TreeNode(7);
//	m->left->left = new TreeNode(15);
//	m->left->left->left = new TreeNode(15);
	
	Solution obj;
	cout << obj.isSameTree(n, m);	
	return 0;
}
