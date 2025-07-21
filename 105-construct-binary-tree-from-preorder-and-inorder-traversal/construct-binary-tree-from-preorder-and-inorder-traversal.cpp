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
    TreeNode* buildhelper(vector<int>&preorder,int prestart,int preend,map<int,int>&mpp,int instart,int inend){
        if(prestart>preend || instart>inend) return NULL;
        int rootval = preorder[prestart];
        TreeNode* root = new TreeNode(rootval);
        int inrootindex = mpp[rootval];
        int numsleft = inrootindex - instart;
        
        root->left = buildhelper(preorder,prestart+1,prestart+numsleft,mpp,instart,instart+numsleft);
        root->right = buildhelper(preorder,prestart+numsleft+1,preend,mpp,instart+numsleft+1,inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        map<int,int>mpp;
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }

        TreeNode* root = buildhelper(preorder,0,n-1,mpp,0,n-1);

        return root;
    }
};