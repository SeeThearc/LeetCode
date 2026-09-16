class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(k+1,INT_MAX)));
        queue<tuple<int,int,int,int>>q;
        dp[0][0][0]=0;
        q.push({0,0,0,0});
        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto [x,y,r,steps] = q.front();
            q.pop();
            //dp[x][y][r] = min(dp[x][y][r],steps);
            if(x==m-1 && y==n-1)return steps;
            for(int i=0;i<4;i++){
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int newsteps = steps+1;
                    int newrem = r + grid[nx][ny];
                    if(newrem<=k && newsteps<dp[nx][ny][newrem]){
                        dp[nx][ny][newrem]=newsteps;
                        q.push({nx,ny,newrem,newsteps});
                    }
                }
            }
        }
        // int ans=INT_MAX;
        // for(int i=0;i<=k;i++){
        //     ans = min(ans,dp[m-1][n-1][i]);
        // }
        // return ans == INT_MAX ? -1 : ans;
        return -1;
    }
};