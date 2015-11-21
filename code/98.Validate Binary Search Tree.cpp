/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 //中序遍历，判断是否为有序数列
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        stack<int> st;
        isValidBST(root, st);
        int temp = st.top();
        st.pop();
        while(stack.empty()) {
            if(temp > st.top()) {
                temp = st.top();
                st.pop();
            }else return false;
        }
        return true;
    }
    
    void isValidBST(TreeNode* root, stack<int> &st) {
        if(!root) return true;
        isValidBST(root->left, st);
        st.push(root->val);
        isValidBST(root->right, st);
    }
};

//较高级中序遍历，通过一个前驱指针，节省了O(n)的空间 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        TreeNode* pre = NULL;
        return isValidBST(root,pre);
    }
    bool isValidBST(TreeNode* root, TreeNode* &pre) {
        if(!root) return true;
        
        if(!isValidBST(root->left, pre)) return false;
        
        if(pre && root->val<=pre->val) return false;
        else pre = root;
        
        if(!isValidBST(root->right, pre)) return false;
        return true;
    } 
};

