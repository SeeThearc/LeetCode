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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>ans;
        bool level=true;
        while(!q.empty()){
            vector<int>lev;
            int s=q.size();
            for(int i=0;i<s;i++){
                auto node = q.front();
                q.pop();
                lev.push_back(node->val);
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(level){
                ans.push_back(lev);
                level=!level;
            }
            else{
                reverse(lev.begin(),lev.end());
                ans.push_back(lev);
                level=!level;
            }
        }
        return ans;
    }
};