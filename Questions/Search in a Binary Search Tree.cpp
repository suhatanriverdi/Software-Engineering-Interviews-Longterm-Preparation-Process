//QUESTION Link ---> https://leetcode.com/problems/search-in-a-binary-search-tree/
//RECURSIVE SOLUTION (Just Solution Class is Included)

//Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

//
//For example, 
//
//Given the tree:
//        4
//       / \
//      2   7
//     / \
//    1   3
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) {
            return nullptr;
        }
        
        if(root->val == val) {
            return root;
        }
        
        if(root->val < val) {
            return searchBST(root->right, val);
        }
        return searchBST(root->left, val);
    }
};
