class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if(grid.empty())return 0;
        queue<pair<int,int>>q;
        int tot=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0)tot++;
                if(grid[i][j]==2)q.push({i,j});
            }
        }
        int minutes=0;
        int cnt=0;
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        while(!q.empty()){
            int k=q.size();
            cnt+=k;
            for(int i=0;i<k;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny]=2;
                    }
                }
            }
            if(!q.empty())minutes++;
        }
        if(cnt==tot){
            return minutes;
        }
        else{
            return -1;
        }
    }
};