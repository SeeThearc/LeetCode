class Solution {
public:
    void dfs(int x,int y,vector<vector<int>>&vis,vector<vector<int>>&heights,auto dir,int m,int n){
        vis[x][y]=1;
        for(int i=0;i<4;i++){
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny] && heights[nx][ny]>=heights[x][y]){
                dfs(nx,ny,vis,heights,dir,m,n);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>pac(m,vector<int>(n,0));
        vector<vector<int>>atl(m,vector<int>(n,0));
        vector<pair<int,int>>dir = {
            {1,0},{-1,0},{0,1},{0,-1}
        };
        for(int i=0;i<m;i++){
            dfs(i,0,pac,heights,dir,m,n);
            dfs(i,n-1,atl,heights,dir,m,n);
        }
        for(int i=0;i<n;i++){
            dfs(0,i,pac,heights,dir,m,n);
            dfs(m-1,i,atl,heights,dir,m,n);
        }
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j]==1 && atl[i][j]==1){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};