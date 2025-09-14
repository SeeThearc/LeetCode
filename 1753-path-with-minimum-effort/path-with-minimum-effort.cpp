class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>maxeff(m,vector<int>(n,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        int dirx[] = {1,0,-1,0};
        int diry[] = {0,1,0,-1};
        pq.push({0,0,0});
        maxeff[0][0]=0;
        while(!pq.empty()){
            auto [dist,x,y] = pq.top();
            pq.pop();
            if(x==m-1 && y==n-1)return maxeff[x][y];
            for(int i=0;i<4;i++){
                int nx = x + dirx[i];
                int ny = y + diry[i];
                if(nx>=0 && nx<m && ny>=0 && ny<n){
                    int neweff = max(abs(heights[nx][ny]-heights[x][y]),dist);
                    if(neweff<maxeff[nx][ny]){
                        maxeff[nx][ny]=neweff;
                        pq.push({neweff,nx,ny});
                    }
                }
            }

        }
        return -1;
    }
};