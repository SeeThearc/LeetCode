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
    bool find(TreeNode* node,int sum){
        if(node==NULL)return false;
        if(sum-node->val==0 && node->left==NULL && node->right==NULL)return true;
        bool left=false,right=false;
        if(node->left){
            left = find(node->left,sum - node->val);
        }
        if(node->right){
            right = find(node->right,sum - node->val);
        }
        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return false;
        return find(root,targetSum);
    }
};