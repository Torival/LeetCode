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
    void recoverTree(TreeNode* root) {
        TreeNode* pre = NULL;
        TreeNode* first = NULL, *second = NULL;
        
        inorder(root, pre, first, second);
        swap(first->val, second->val);
    }
    void inorder(TreeNode* root, TreeNode* &pre, TreeNode* &first, TreeNode* &second) {
        if(!root) return ;
        if(root->left) inorder(root->left, pre, first, second);
        if(pre && root->val < pre ->val) {
            if(!first) first = pre;
            second = root;
        }
        pre = root;
        if(root->right) inorder(root->right, pre, first, second);
    }
};
