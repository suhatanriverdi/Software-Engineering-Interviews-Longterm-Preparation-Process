// Question Link ---> https://leetcode.com/problems/binary-tree-right-side-view/
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
		vector<int> rightMostNodes;
		int n;
	    vector<int> rightSideView(TreeNode* root) {
	        if(root == NULL) {
	    		return rightMostNodes;	
			}
	    	queue<TreeNode*> q;
	    	q.push(root);
	    	while(!q.empty()) {
	    		int level = q.size();
	    		while(level > 0) { // In Level
		    		TreeNode* temp = q.front();
		    		q.pop();
		    		n = temp->val;
		    		cout << temp->val << " ";
		    		if(temp->left != NULL) {
		    			q.push(temp->left);
					}
					
					if(temp->right != NULL) {
		    			q.push(temp->right);
					}
					level--;
				}
				rightMostNodes.push_back(n);
				cout << endl;
			}
			return rightMostNodes;
		}
};

int main(void) {
	TreeNode *n = new TreeNode(1);
	n->left = new TreeNode(3);
	n->right = new TreeNode(2);	
	n->right->right = new TreeNode(9);	
	n->left->left = new TreeNode(5);
	n->left->right = new TreeNode(3);
	
//			1
//		  /  \
//		 3    2
//		/ \	   \
//	   5  3 	9

//==========> Default Test Case <==========
	
//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(2);
//	n->right = new TreeNode(3);	
//	n->left->right = new TreeNode(5);
	
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

	vector<int> res;
	Solution obj;
	res = obj.rightSideView(n);
	for(int i=0; i<res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}
