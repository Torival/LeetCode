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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> vec;
        TreeNode* ptail = root;
        
        while(st.size() || ptail) {
            while(ptail) {
                st.push(ptail);
                vec.push_back(ptail->val);
                ptail = ptail->left;
            }
            
            if(st.size()) {
                ptail = st.top()->right;
                st.pop();
            }
        } 
        return vec;
    }
};
