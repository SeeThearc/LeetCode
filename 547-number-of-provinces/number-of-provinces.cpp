class Solution {
public:
    void dfs(vector<int>adjLis[],int start,int n,vector<int>&vis){
        vis[start]=1;
        for(auto it:adjLis[start]){
            if(!vis[it]){
                dfs(adjLis,it,n,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>adjLis[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                if(isConnected[i][j]){
                    adjLis[i].push_back(j);
                }
            }
        }
        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adjLis,i,n,vis);
                ans++;
            }
        }
        return ans;
    }
};