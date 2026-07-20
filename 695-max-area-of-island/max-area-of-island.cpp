class Solution {
public:
    void dfs(int x,int y,int m,int n,vector<vector<int>>&grid,vector<vector<int>>&vis,vector<pair<int,int>>&dir,int &val){
        val++;
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1 && !vis[nx][ny]){
                dfs(nx,ny,m,n,grid,vis,dir,val);
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    int val=0;
                    dfs(i,j,m,n,grid,vis,dir,val);
                    ans = max(ans,val);
                }
            }
        }
        return ans;
    }
};