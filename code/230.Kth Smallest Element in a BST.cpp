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
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallest(root, 0, k);
    }
    int kthSmallest(TreeNode* root,int &num, int k) {
        if(!root) return 0;
        int val;
        if(num != k) val = kthSmallest(root->left, num, k);
        if(num == k) return val;
        if(++num == k)  return root->val;
        if(num != k) val = kthSmallest(root->right, num, k);
        if(num == k) return val;
        return 0;
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        while(k || root) {
            while(root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            if(--k == 0) return root->val;
            root = root->right;
            st.pop();
        }
        return 0;
    }
};
