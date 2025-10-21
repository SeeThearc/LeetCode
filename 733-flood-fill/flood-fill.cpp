class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int org = image[sr][sc];
        int dirx[] = {0,0,1,-1};
        int diry[] = {1,-1,0,0};
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        q.push({sr,sc});
        visited[sr][sc]=1;
        image[sr][sc]=color;
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && !visited[nx][ny] &&image[nx][ny]==org){
                    q.push({nx,ny});
                    image[nx][ny]=color;
                    visited[nx][ny]=1;
                }
            }
        }
        return image;
    }
};