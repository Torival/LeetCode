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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        levelOrder(root, vec, 0);
        return vec;
    }
    void levelOrder(TreeNode* root, vector<vector<int>> &vec, int depth) {
        if(!root) return ;
        if(vec.size() == depth)
            vec.push_back(vector<int>());
        vec[depth].push_back(root->val);
        if(root->left) levelOrder(root->left, vec, depth+1);
        if(root->right) levelOrder(root->right, vec, depth+1);
    }
};
