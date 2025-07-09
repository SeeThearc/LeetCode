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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        int width=0;
        while(!q.empty()){
            int size=q.size();
            unsigned long long f=0,l=0;
            unsigned long long mmin = q.front().second;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front().first;
                unsigned long long x = q.front().second - mmin;
                q.pop();
                if(i==0)f=x;
                if(i==size-1)l=x;
                if(temp->left){
                    q.push({temp->left,(2*x)+1});
                }
                if(temp->right){
                    q.push({temp->right,(2*x)+2});
                }
            }
            if(l-f+1>width){
                width=l-f+1;
            }
        }
        return width;
    }
};