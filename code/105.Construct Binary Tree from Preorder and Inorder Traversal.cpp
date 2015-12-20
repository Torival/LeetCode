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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size()-1, inorder, 0);
    }
    TreeNode* buildTree(vector<int>& preorder, int start1, int end1, vector<int>& inorder, int start2) {
        if(end1 -start1 < 0) return NULL;
        TreeNode *root = new TreeNode(preorder[start1]);
        int index = start2;
        while(preorder[start1] != inorder[index]) index++;
        root->left = buildTree(preorder, start1+1, start1+index-start2, inorder, start2);
        root->right = buildTree(preorder, start1+index-start2+1, end1, inorder, index+1);
        return root;
    }
};
