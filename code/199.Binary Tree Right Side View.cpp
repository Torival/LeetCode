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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        vector<vector<int>> vec;
        rightSideView(root, vec, 0);
        for(int i=0; i<vec.size(); i++) {
            v.push_back(vec[i][vec[i].size()-1]);
        }
        return v;
    }
    
    void rightSideView(TreeNode* root, vector<vector<int>> &vec, int depth) {
        if(!root) return ;
        if(depth == vec.size()) vec.push_back(vector<int>());
        vec[depth].push_back(root->val);
        rightSideView(root->left, vec, depth+1);
        rightSideView(root->right, vec, depth+1);
    }
};
