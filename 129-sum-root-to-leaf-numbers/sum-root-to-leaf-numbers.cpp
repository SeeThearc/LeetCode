/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum=0;
    void dfs(TreeNode* root,string &s){
        if(!root)return ;
        s+=root->val+'0';
        if(!root->left && !root->right){
            sum+=stoi(s);
        }
        dfs(root->left,s);
        dfs(root->right,s);
        s.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        if(!root)return 0;
        string s="";
        dfs(root,s);
        return sum;
    }
};