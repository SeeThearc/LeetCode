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
    map<TreeNode*,TreeNode*> parentsmap(TreeNode* root){
        map<TreeNode*,TreeNode*>mpp;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                mpp[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                mpp[temp->right] = temp;
                q.push(temp->right);
            }
        }
        return mpp;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*,TreeNode*>parentmap = parentsmap(root);
        set<TreeNode*>ancestors;
        while(p){
            ancestors.insert(p);
            p=parentmap[p];
        }
        while(q){
            if(ancestors.count(q))return q;
            q=parentmap[q];
        }
        return nullptr;
    }
};