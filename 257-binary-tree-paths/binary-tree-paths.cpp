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
    vector<string>ans;
    void pathutil(TreeNode* root,string s){
        if(!root)return;
        if(root->left==NULL && root->right==NULL){
            s.append("->");
            s.append(to_string(root->val));
            ans.push_back(s);
        }
        else{
            s.append("->");
            s.append(to_string(root->val));
            pathutil(root->left,s);
            pathutil(root->right,s);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        if(!root){
            return ans;
        }
        if(root->left==NULL && root->right==NULL){
            s.append(to_string(root->val));
            ans.push_back(s);
            return ans;
        }
        s.append(to_string(root->val));
        pathutil(root->left,s);
        pathutil(root->right,s);
        return ans;
    }
};