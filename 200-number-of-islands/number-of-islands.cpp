class Solution {
public:
    void bfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j,int m,int n){
        int dirx[] = {0,0,1,-1};
        int diry[] = {1,-1,0,0};
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first;
            int y = it.second;
            for(int k=0;k<4;k++){
                int nx = x + dirx[k];
                int ny = y + diry[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]=='1' && !vis[nx][ny]){
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {

        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    bfs(grid,vis,i,j,m,n);
                    c++;
                }
            }
        }
        return c;
    }
};