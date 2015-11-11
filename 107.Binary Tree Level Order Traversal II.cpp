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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> vec;
        if(!root) return vec;
        TreeNode* ptail;
        vector<int> vec1;
        queue<TreeNode*> q;
        int count = 1;      //判断当前层是否全部放入vector 
        int k = 0;          // 来统计下一层有多少个 
        
        q.push(root);
        while(!q.empty()) {
            ptail = q.front();
            vec1.push_back(ptail->val);
            count--;
            q.pop();
            if(ptail->left) {    
                q.push(ptail->left);
                k++;
            }
            if(ptail->right) {
                q.push(ptail->right);
                k++;
            }
            if(!count || q.empty()){
                vec.push_back(vec1);
                vec1.clear();
                count = k;
                k = 0;
            }
        }
        reverse(vec.begin(),vec.end());
        return vec;
    }
};
