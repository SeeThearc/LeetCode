class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m =grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]!=0)c++;
            }
        }
        int ans=0;
        int dirx[] = {0,0,1,-1};
        int diry[] = {1,-1,0,0};
        int cf=0;
        while(!q.empty()){
            bool found=false;
            int s = q.size();
            cf+=s;
            for(int j=0;j<s;j++){
                auto temp = q.front();
                int x = temp.first;
                int y = temp.second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx = x+dirx[i];
                    int ny = y+diry[i];
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        found=true;
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                    }
                }
            }
            if(found)ans++;
            found=false;
        }
        int fin;
        if(c==cf?fin=ans:fin=-1);
        return fin;
    }
};