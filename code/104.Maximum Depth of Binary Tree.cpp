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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int depthl = 0;
        int depthr = 0;
        depthl = maxDepth(root->left);
        depthr = maxDepth(root->right);
        return depthl > depthr ? depthl+1 : depthr+1;
    }
};
