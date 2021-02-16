// Question Link ---> https://leetcode.com/problems/check-completeness-of-a-binary-tree/
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        int L = height(root->left); // Save Left Depht
        int R = height(root->right); // Save Right Depht
        if(L == R && isFullTree(root->left) && isCompleteTree(root->right)) {
            return true;
        }
        if(L == R + 1 && isCompleteTree(root->left) && isFullTree(root->right)) {
            return true;
        }
        return false;
    }
    
    bool isFullTree(TreeNode* h) {
        if(h == NULL) {
            return true;
        }
        if(height(h->left) != height(h->right)) {
             return false;
        }
        return isFullTree(h->left) && isFullTree(h->right);
    }
    
    int height(TreeNode* h) {
        if(h == NULL) {
            return 0;
        }
        return max(height(h->left), height(h->right)) + 1;
    }
};
