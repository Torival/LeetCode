/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
/**
 *算法思想： (1) 若当前节点为左节点，并且右节点存在，则next指向右节点
 *           (2) 其他情况，通过双亲节点的链表查找当前节点的下一个节点
 *           (3) 若上层链表一直查找到NULL，则当前节点的next是NULL
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        connect(root, NULL);
    }
    void connect(TreeLinkNode *root, TreeLinkNode* pre) {
        if(!root) return ;
        
        if(pre && (root == pre->left) && pre->right) root->next = pre->right;
        else if(pre) {
            pre = pre->next;
            while(pre && !pre->left && !pre->right) pre = pre->next;
            
            if(pre) {
                if(pre->left) root->next = pre->left;
                else root->next = pre->right;
            }
        }
        if(root->right) connect(root->right, root);
        if(root->left) connect(root->left, root);
    }
};
