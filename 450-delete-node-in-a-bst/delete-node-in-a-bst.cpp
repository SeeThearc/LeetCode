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
    TreeNode* minvalue(TreeNode* root){
        while(root && root->left!=NULL)root=root->left;
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        else if(key<root->val) root->left = deleteNode(root->left,key);
        else if(key>root->val) root->right = deleteNode(root->right,key);
        else{
            if(root->left==NULL && root->right==NULL){
                delete(root);
                return NULL;
            }
            else if(root->left==NULL){
                TreeNode*y = root->right;
                delete(root);
                return y;
            }
            else if(root->right==NULL){
                TreeNode*y = root->left;
                delete(root);
                return y;
            }
            else{
                TreeNode* y = minvalue(root->right);
                root->val = y->val;
                root->right = deleteNode(root->right,y->val);
            }
        }
        return root;
    }
};