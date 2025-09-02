class Solution {
public:
    void dfs(vector<vector<int>>&grid,int x,int y,vector<vector<int>>&vis,int dirx[] , int diry[]){
        vis[x][y]=1;
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0;i<4;i++){
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1 && !vis[nx][ny]){
                dfs(grid,nx,ny,vis,dirx,diry);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dirx[] = {0,0,1,-1};
        int diry[] = {1,-1,0,0};
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            if(grid[i][0]==1 && !vis[i][0]){
                dfs(grid,i,0,vis,dirx,diry);
            }
            if(grid[i][n-1]==1 && !vis[i][n-1]){
                dfs(grid,i,n-1,vis,dirx,diry);
            }
        }
        for(int i=0;i<n;i++){
            if(grid[0][i]==1 && !vis[0][i]){
                dfs(grid,0,i,vis,dirx,diry);
            }
            if(grid[m-1][i] && !vis[m-1][i]){
                dfs(grid,m-1,i,vis,dirx,diry);
            }
        }
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};