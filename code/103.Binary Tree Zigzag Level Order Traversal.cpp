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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> vec;
        if(!root) return vec;
        zigzagLevelOrder(root,vec,0);
        for(int i=1; i<vec.size(); i+=2) {
            std::reverse(vec[i].begin(), vec[i].end());
        }
        return vec;
    }
    void zigzagLevelOrder(TreeNode* root, vector<vector<int>> &vec, int depth) {
        if(!root) return ;
        if(depth == vec.size()) vec.push_back(vector<int>());
        vec[depth].push_back(root->val);
        zigzagLevelOrder(root->left, vec, depth+1);
        zigzagLevelOrder(root->right, vec, depth+1);
    }
};
