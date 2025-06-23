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
    int maxi=INT_MIN;
    int maxsum(TreeNode* root){
        if(root==NULL)return 0;
        int sl=max(0,maxsum(root->left));
        int sr=max(0,maxsum(root->right));
        maxi=max(maxi,root->val+sl+sr);
        return root->val+max(sl,sr);
    }
    int maxPathSum(TreeNode* root) {
        maxsum(root);
        return maxi;
    }
};