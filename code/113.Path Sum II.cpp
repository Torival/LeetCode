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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> vec;
        vector<int> v;
        pathSum(root, sum, vec, v, 0);
        return vec;
    }
    
    void pathSum(TreeNode* root, int sum, vector<vector<int>> &vec, vector<int> v, int total) { 
        if(!root) return ;
        
        v.push_back(root->val);
        if(!root->left && !root->right && sum == total + root->val) vec.push_back(v);
        
        pathSum(root->left, sum, vec, v, total + root->val);
        pathSum(root->right, sum, vec, v, total + root->val);
    }
};
