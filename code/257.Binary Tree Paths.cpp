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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vec;
        if(!root) return vec;
        string s;
        
        s += to_string(root->val);
        if(root->left) binaryTreePaths(root->left, s, vec);
        if(root->right) binaryTreePaths(root->right, s, vec);
        if(!root->left && !root->right) vec.push_back(s);
        return vec;
    }
    void binaryTreePaths(TreeNode* bt, string s, vector<string> &vec) {
        s += "->";
        s += to_string(bt->val);
        if(!bt->left && !bt->right) {
            vec.push_back(s);
            return ;
        }
        if(bt->left) binaryTreePaths(bt->left, s, vec);
        if(bt->right) binaryTreePaths(bt->right, s, vec);
    }
};

