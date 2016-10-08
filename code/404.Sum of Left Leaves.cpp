/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return sumOfLeftLeaves(root, 0);
    }
    
    int sumOfLeftLeaves(TreeNode* root, int flag) {
        if(!root) return 0;
        if(flag && !root->left && !root->right) return root->val;
        
        return sumOfLeftLeaves(root->left, 1) + sumOfLeftLeaves(root->right, 0);
    }
};