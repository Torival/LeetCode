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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        TreeNode *temp, *front;
        queue<TreeNode*> queue;
        queue.push(root);
        while(queue.size()) {
            front = queue.front();
            temp = front->left;
            front->left = front->right;
            front->right = temp;
            
            if(front->left) queue.push(front->left);
            if(front->right) queue.push(front->right);
            
            queue.pop();
        }
        return root;
    }
};

