class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<char>>&grid,vector<pair<int,int>>&dir){
        int m =grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            for(int i=0;i<4;i++){
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && grid[nx][ny]=='1'){
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
        int isl = 0;
        vector<pair<int,int>>dir = {{0,1},{1,0},{-1,0},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    isl++;
                    bfs(i,j,vis,grid,dir);
                }
            }
        }
        return isl;
    }
};