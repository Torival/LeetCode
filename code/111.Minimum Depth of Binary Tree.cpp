/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *结点三种状态：叶子，单支结点，双支结点 
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        int depthl = 0;
        int depthr = 0;
        
        if(!root->left && !root->right) return 1;
        
        depthl = minDepth(root->left);
        depthr = minDepth(root->right);
        
        if(!depthl) return depthr+1;
        if(!depthr) return depthl+1;
        
        return depthl < depthr ? depthl+1 : depthr+1;
    }
};
