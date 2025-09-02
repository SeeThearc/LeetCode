class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc]==color)return image;
        int org = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        queue<pair<int,int>>q;
        q.push({sr,sc});
        image[sr][sc]=color;
        int dirx[] = {0,0,1,-1};
        int diry[] = {1,-1,0,0};
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;
            for(int i=0;i<4;i++){
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n && image[nx][ny]==org){
                    image[nx][ny]=color;
                    q.push({nx,ny});
                }
            }
        }
        return image;
    }
};