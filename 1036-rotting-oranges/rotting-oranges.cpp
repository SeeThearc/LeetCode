class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        int dirx[] = {0,0,1,-1};
        int diry[] = {1,-1,0,0};
        int total=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]!=0)total++;
            }
        }
        if(total==0)return 0;
        int rot=0;
        int min=-1;
        while(!q.empty()){
            int size = q.size();
            rot+=size;
            min++;
            for(int i=0;i<size;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nx = x + dirx[k];
                    int ny = y + diry[k];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
        }
        int ans=-1;
        if(rot==total?ans=min:ans=-1);
        return ans;
    }
};