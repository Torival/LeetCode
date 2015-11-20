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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> stack;
        
        while(root || !stack.empty()) {
            while(root) {
                stack.push(root);
                root = root->left;
            }
            
            if(!stack.empty()) {
                root = stack.top()->right;
                vec.push_back(stack.top()->val);
                stack.pop();
            }
        }
        return vec;
    }
};
