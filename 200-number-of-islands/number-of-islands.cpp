class Solution {
public:
    void bfs(int i,int j,int m,int n,vector<vector<char>>&grid,vector<vector<int>>&vis,vector<pair<int,int>>&dir){
        queue<pair<int,int>>q;
        vis[i][j]=1;
        q.push({i,j});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nx = x + dir[k].first;
                int ny = y + dir[k].second;
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]=='1' && !vis[nx][ny]){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int isl=0;
        vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    isl++;
                    bfs(i,j,m,n,grid,vis,dir);
                }
            }
        }
        return isl;
    }
};