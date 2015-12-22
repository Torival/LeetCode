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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vec;
        levelOrderBottom(root, vec, 0);
        reverse(vec.begin(),vec.end());
        return vec;
    }
    void levelOrderBottom(TreeNode* root, vector<vector<int>> &vec, int depth) {
        if(!root) return ;
        if(vec.size() == depth)
            vec.push_back(vector<int>());
        vec[depth].push_back(root->val);
        if(root->left) levelOrderBottom(root->left, vec, depth+1);
        if(root->right) levelOrderBottom(root->right, vec, depth+1);
    }
};
