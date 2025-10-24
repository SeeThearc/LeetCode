class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>&vis,vector<vector<char>>&grid,vector<pair<int,int>>&dir,int m,int n){
        vis[x][y]=1;
        for(auto [dx,dy]:dir){
            int nx = x + dx;
            int ny = y + dy;
            if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny]=='1'){
                dfs(nx,ny,vis,grid,dir,m,n);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int isl=0;
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<pair<int,int>>dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    dfs(i,j,vis,grid,dir,m,n);
                    isl++;
                }
            }
        }
        return isl;
    }
};