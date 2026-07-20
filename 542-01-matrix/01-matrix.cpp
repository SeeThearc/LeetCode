class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int x = it.first.first;
            int y = it.first.second;
            int step = it.second;
            mat[x][y] = step;
            for(int i=0;i<4;i++){
                int nx = x + dir[i].first;
                int ny = y + dir[i].second;
                if(nx>=0 && nx<m && ny>=0 && ny<n && !vis[nx][ny]){
                    vis[nx][ny]=1;
                    q.push({{nx,ny},step+1});
                }
            }
        }
        return mat;
    }
};