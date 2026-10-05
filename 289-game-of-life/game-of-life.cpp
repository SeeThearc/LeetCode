class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<pair<int,int>>dir = {{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};
        vector<vector<int>>old = board;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int nei=0;
                for(int k=0;k<8;k++){
                    int nx = i + dir[k].first;
                    int ny = j + dir[k].second;
                    if(nx>=0 && nx<m && ny>=0 && ny<n && old[nx][ny]==1){
                        nei++;
                    }
                }
                if(old[i][j]){
                    if(nei<2)board[i][j]=0;
                    else if(nei>=4)board[i][j]=0;
                }
                else{
                    if(nei==3)board[i][j]=1;
                }
            }
        }
    }
};