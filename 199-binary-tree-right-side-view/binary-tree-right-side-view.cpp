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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(!root)return ans;
        map<int,int>mpp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto p =q.front();
            q.pop();
            TreeNode* temp = p.first;
            int horiz = p.second;
            mpp[horiz] = temp->val;
            if(temp->left){
                q.push({temp->left,horiz+1});
            }
            if(temp->right){
                q.push({temp->right,horiz+1});
            }
        }
        for(auto mp:mpp){
            ans.push_back(mp.second);
        }
        return ans;
    }
};