/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root) return ;
        if(root->left && root->right) {
            root->left->next = root->right;
            if(root->left->right && root->right->left) 
                root->left->right->next = root->right->left;
            if(root->right->right && root->right->next && root->right->next->left) 
                root->right->right->next = root->right->next->left;
        }
        connect(root->left);
        connect(root->right);
    }
};
