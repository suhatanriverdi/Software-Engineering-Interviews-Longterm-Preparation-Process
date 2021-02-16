// Question Link ---> https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
		
struct TreeNode {
    int val;
//    int level; // We can also use this one, instead of queue-pair
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};		

class Solution {
	public:
	    vector<int> largestValues(TreeNode* root) {
	        return BFS(root);
	    }
	    
	    vector<int> BFS(TreeNode* root) {
	    	if(root == NULL) {
	    		return vector<int>();	
			}
			cout << "Number of Levels: " << treeHeight(root) << endl;
			vector<int> largestValueInEachLevel(treeHeight(root));
	    	int maxVal = INT_MIN;
	    	queue<pair<TreeNode*, int>> q;
	    	q.push({root, 1});
	    	largestValueInEachLevel[0] = root->val; // Largest[0] => Level 1, Largest[1] => Level 2 ...
	    	while(!q.empty()) {
	    		pair<TreeNode*, int> CurrentNode = q.front();
		    	int Currentlevel = CurrentNode.second;
	    		q.pop();
	    		cout << CurrentNode.first->val << "(level: " << Currentlevel << ") ";
	    		if(CurrentNode.first->left != NULL) {
	    			q.push({CurrentNode.first->left, Currentlevel+1});
			    	maxVal = max(CurrentNode.first->left->val, maxVal);
	    			largestValueInEachLevel[CurrentNode.second] = maxVal;
				}
				
				if(CurrentNode.first->right != NULL) {
	    			q.push({CurrentNode.first->right, Currentlevel+1});
	    			maxVal = max(CurrentNode.first->right->val, maxVal);
	    			largestValueInEachLevel[CurrentNode.second] = maxVal;
				}
				maxVal = INT_MIN; // Reset maxVal for above levels
			}
			cout << endl;
			return largestValueInEachLevel;
		}
		
		int treeHeight(TreeNode* root) {
			if(root == NULL) {
				return 0;
			}
	        return 1 + max(treeHeight(root->left), treeHeight(root->right));
	    }
};

int main(void) {	

	TreeNode *n = new TreeNode(1);
	n->left = new TreeNode(3);
	n->right = new TreeNode(2);	
	n->right->right = new TreeNode(9);	
	n->left->left = new TreeNode(5);
	n->left->right = new TreeNode(3);

	vector<int> res;
	Solution obj;
	res = obj.largestValues(n);
	for(int i=0; i<res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}
