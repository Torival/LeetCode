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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder, 0, postorder, 0, postorder.size()-1);
    }
    TreeNode* buildTree(vector<int>& inorder, int start1, vector<int>& postorder, int start2, int end) {
        if(end - start2 < 0) return NULL;
        TreeNode* root = new TreeNode
        (postorder[end]);
        int index = start1;
        while(inorder[index] != postorder[end]) index++;
        root->left = buildTree(inorder, start1, postorder, start2, start2+index-start1-1);
        root->right = buildTree(inorder, index+1, postorder, start2+index-start1, end-1);
        return root;
    }
};
