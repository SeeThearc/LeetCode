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
    int diameter=0;
    int calcheight(TreeNode* root){
        if(!root) return 0;
        int ml=calcheight(root->left);
        int mr=calcheight(root->right);
        diameter=max(diameter,ml+mr);
        return 1 + max(ml,mr);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        calcheight(root);
        return diameter;
    }
};