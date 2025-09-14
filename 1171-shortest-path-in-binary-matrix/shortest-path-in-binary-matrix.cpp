class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;
        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0]=1;
        vector<pair<int,int>>dir = {
            {1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,1},{-1,-1},{1,-1}
        };
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;
            int dist = grid[x][y];
            if(x==n-1 && y==n-1)return dist;
            for(auto [dx,dy] : dir){
                int nx = x + dx;
                int ny = y + dy;
                if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
                    q.push({nx,ny});
                    grid[nx][ny] = 1 + dist;
                }
            }
        }
        return -1;
    }
};