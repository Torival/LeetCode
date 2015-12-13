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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        TreeNode* pleft = root;
        TreeNode* pright = root;
        int high = 0;
        for(;pleft && pright; high++) {
            pleft = pleft->left;
            pright = pright->right;
        }
        if(pleft == pright) return (1 << high)-1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};
