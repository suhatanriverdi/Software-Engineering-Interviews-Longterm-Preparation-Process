// Question Link ---> https://www.techiedelight.com/level-order-traversal-binary-tree/
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
	    void levelOrderTraversal(TreeNode* root) {
	        BFS(root);
	    }
	    
	    void BFS(TreeNode* root) {
	    	if(root == NULL) {
	    		return;	
			}
	    	queue<TreeNode*> q;
	    	q.push(root);
	    	while(!q.empty()) {
	    	//	int level = q.size();
	    	//	while(level > 0) { // In Level
		    		TreeNode* temp = q.front();
		    		q.pop();
		    		cout << temp->val << " ";
		    		if(temp->left != NULL) {
		    			q.push(temp->left);
					}
					
					if(temp->right != NULL) {
		    			q.push(temp->right);
					}
					//level--;
				}
				cout << endl;
		}
};

int main(void) {
//==========> Default Test Case <==========

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(3);
//	n->right = new TreeNode(2);	
//	n->right->right = new TreeNode(9);	
//	n->left->left = new TreeNode(5);
//	n->left->right = new TreeNode(3);
	
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

	TreeNode *n = new TreeNode(1);
	n->right = new TreeNode(20);		
	n->left = new TreeNode(9);
	n->right->left = new TreeNode(7);
	n->right->left->left = new TreeNode(7);
	n->left->left = new TreeNode(15);
	n->left->left->left = new TreeNode(15);
	
	Solution obj;
	obj.levelOrderTraversal(n);
	return 0;
}
