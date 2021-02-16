// Question Link ---> https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
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
		vector<int> largest;
	    vector<int> largestValues(TreeNode* root) {
	        BFS(root);
	        return largest;
	    }
	    
	    void BFS(TreeNode* root) {
	    	if(root == NULL) {
	    		return;	
			}
			int maxVal = INT_MIN;
	    	queue<TreeNode*> q;
	    	q.push(root);
	    	int level = 0;
	    	while(!q.empty()) {
	    		int NumOfNodesInlevel = q.size();
	    		while(NumOfNodesInlevel > 0) { // In Level
		    		TreeNode* temp = q.front();
		    		q.pop();
		    		cout << temp->val << " ";
			    	maxVal = max(temp->val, maxVal);
		    		//cout << "Level: " << level << endl;
		    		if(temp->left != NULL) {
		    			q.push(temp->left);
					}
					
					if(temp->right != NULL) {
		    			q.push(temp->right);
					}
					NumOfNodesInlevel--;
				}
				level++;
				largest.push_back(maxVal);
				maxVal = INT_MIN;
				cout << endl;
			}
		}
};

int main(void) {	
//_==========> Default Test Case <==========

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

//	TreeNode *n = new TreeNode(0);

//	TreeNode *n = new TreeNode(-1);

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(9);

//	TreeNode *n = new TreeNode(1);
//	n->left = new TreeNode(-999);

//	TreeNode *n = new TreeNode(-1);
//	n->left = new TreeNode(9);

//	TreeNode *n = new TreeNode(0);
//	n->left = new TreeNode(-1);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(20);

//	TreeNode *n = new TreeNode(-1);
//	n->right = new TreeNode(20);

//	TreeNode *n = new TreeNode(1);
//	n->right = new TreeNode(-99);

//	TreeNode *n = new TreeNode(-2);
//	n->right = new TreeNode(-999);	

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

	vector<int> res;
	Solution obj;
	res = obj.largestValues(n);
	for(int i=0; i<res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}
