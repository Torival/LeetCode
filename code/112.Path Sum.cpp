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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return hasPathSum(root, 0, sum);
    }
    bool hasPathSum(TreeNode* root, int num, int sum) {
        if(!root) return false;
        
        if(!root->left && !root->right && num+root->val == sum) return true;
        
        if(hasPathSum(root->left, num+root->val, sum)) return true;
        if(hasPathSum(root->right, num+root->val, sum)) return true;
        
        return false;
    }
};

