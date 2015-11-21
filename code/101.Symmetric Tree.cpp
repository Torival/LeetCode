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
    bool isSymmetric(TreeNode* root) {
       if(!root) return true;
       return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* front, TreeNode* rear) {
        if(!front && !rear) return true;
        else {
            if(!front || !rear) return false;
            if(front->val != rear->val) return false;
            if(!isSymmetric(front->left, rear->right)) return false;
            return isSymmetric(front->right, rear->left);
        }
    }
};
