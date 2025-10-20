class Solution {
public:
    void bfs(int node,vector<int>&visited,vector<vector<int>>&isConnected){
        queue<int>q;
        q.push(node);
        visited[node]=1;
        while(!q.empty()){
            int nod = q.front();
            q.pop();
            for(int i=0;i<isConnected[nod].size();i++){
                if(i!=nod && isConnected[nod][i] && !visited[i]){
                    visited[i]=1;
                    q.push(i);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int>visited(n,0);
        int p=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                p++;
                bfs(i,visited,isConnected);
            }
        }
        return p;
    }
};