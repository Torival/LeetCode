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
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;
        return sumNumbers(root, 0);
    }
    int sumNumbers(TreeNode* root, long long num) {
        if(!root) return 0;
        long long sum = 10*num + root->val;
        
        if(root->left || root->right) {
            sum = sumNumbers(root->left, num*10 + root->val);
            sum += sumNumbers(root->right, num*10 + root->val);
        }
        
        return sum;
    }
};
