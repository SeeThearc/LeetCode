class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        vector<vector<int>>dis(n,vector<int>(m));
        int dirx[] = {0,0,1,-1};
        int diry[] = {1,-1,0,0};
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x = temp.first.first;
            int y = temp.first.second;
            int step = temp.second;
            dis[x][y] = step;
            for(int i=0;i<4;i++){
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny]){
                    q.push({{nx,ny},step+1});
                    vis[nx][ny]=1;
                }
            }
        }
        return dis;
    }
};