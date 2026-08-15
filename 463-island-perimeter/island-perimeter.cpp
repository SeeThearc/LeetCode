class Solution {
public:
    int bfs(int i,int j,vector<vector<int>>&grid,vector<vector<int>>&vis,vector<pair<int,int>>&dir,int m,int n){
        queue<pair<int,int>>q;
        int peri=0;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;
            int edges=4;
            for(int i=0;i<4;i++){
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;
                if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                    if(!vis[nx][ny]){
                        q.push({nx,ny});
                        vis[nx][ny]=1;
                    } 
                    edges--;
                }
            }
            peri+=edges;
        }
        return peri;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    return bfs(i,j,grid,vis,dir,m,n);
                }
            }
        }
        return -1;
    }
};