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
    int ksmall,x=0;
    void inorder(TreeNode* root,int k){
        if(root){
            inorder(root->left,k);
            x++;
            if(x==k){
                ksmall=root->val;
            }
            inorder(root->right,k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root,k);
        return ksmall;
    }
};