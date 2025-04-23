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
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return isMirror(root->left,root->right);
    }
    bool isMirror(TreeNode *t,TreeNode *q){
        if(!t&&!q){
            return true;
        }
        if(!t||!q||t->val!=q->val){
            return false;
        }
        return isMirror(t->left,q->right)&&isMirror(t->right,q->left);
    }
};