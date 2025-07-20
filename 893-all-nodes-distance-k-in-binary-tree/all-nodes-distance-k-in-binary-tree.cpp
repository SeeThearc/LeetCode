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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>parentmap;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->left){
                parentmap[temp->left] = temp;
                q.push(temp->left);
            }
            if(temp->right){
                parentmap[temp->right] = temp;
                q.push(temp->right);
            }
        }

        queue<pair<TreeNode*,int>>que;
        map<TreeNode*,bool>visited;
        que.push({target,0});
        visited[target] = true;
        vector<int>ans;
        while(!que.empty()){
            TreeNode* temp = que.front().first;
            int x = que.front().second;
            que.pop();
            if(x==k){
                ans.push_back(temp->val);
                continue;
            }
            if(temp->left && !visited[temp->left]){
                visited[temp->left] = true;
                que.push({temp->left,x+1});
            }
            if(temp->right && !visited[temp->right]){
                visited[temp->right] = true;
                que.push({temp->right,x+1});
            }
            if(parentmap.count(temp) && !visited[parentmap[temp]]){
                visited[parentmap[temp]]=true;
                que.push({parentmap[temp],x+1});
            }
        }
        return ans;
    }
};