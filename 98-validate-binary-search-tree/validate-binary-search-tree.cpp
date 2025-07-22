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
    int minValue(TreeNode* root){
        while(root && root->left){
            root=root->left;
        }
        return root->val;
    }
    int maxValue(TreeNode* root){
        while(root && root->right){
            root=root->right;
        }
        return root->val;
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        else if(root->left && maxValue(root->left)>=root->val)return false;
        else if(root->right && minValue(root->right)<=root->val)return false;
        else if(!isValidBST(root->left) || !isValidBST(root->right)) return false;
        else return true;
    }
};