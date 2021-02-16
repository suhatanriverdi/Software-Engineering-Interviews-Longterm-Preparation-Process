// Question Link ---> https://leetcode.com/problems/binary-tree-paths/description/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
		
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};		
		
class Solution {
	public:
		vector<string> s;
		string path;
		vector<string> binaryTreePaths(TreeNode* root) {
			if (root == NULL) {
				return s;
			}
			DFS(root, path); // &string
			return s;
		}
	
		void DFS(TreeNode *root, string path) {
			if(root != NULL) {
				path.append(to_string(root->val)+"->");
				if(!root->right && !root->left) {
					path.pop_back();
					path.pop_back();
					s.push_back(path);
				}
				else {
					DFS(root->left, path);
					DFS(root->right, path);
				}
			}
		}
};

int main(void) {
//==========> Default Test Case <==========
	
	TreeNode *n = new TreeNode(1);
	n->left = new TreeNode(2);
	n->right = new TreeNode(3);	
	n->left->right = new TreeNode(5);
	
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

	vector<string> res;
	Solution obj;
	res = obj.binaryTreePaths(n);
	for(int i=0; i<res.size(); i++) {
		cout << res[i] << " ";
	}
	return 0;
}
