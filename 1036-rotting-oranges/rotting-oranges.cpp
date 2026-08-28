class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;
        vector<pair<int,int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
        if(n==1 && m==1 && grid[0][0]==1)return -1;
        if(n==1 && m==1)return 0;
        int r=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                if(grid[i][j]==1)r++;
            }
        }
        int min=0,c=0;
        bool found=false;
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int nx = x + dir[j].first;
                    int ny = y + dir[j].second;
                    if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        c++;
                        found=true;
                    }
                }
            }
            if(found){
                min++;
                found=false;
            }
        }
        //cout<<min;
        cout<<c<<" "<<r;
        if(c==r)return min;
        return -1;
    }
};