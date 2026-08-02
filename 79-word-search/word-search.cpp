class Solution {
public:
    bool find(int x,int y,int idx,string &word,vector<pair<int,int>>&dir,vector<vector<int>>&vis,vector<vector<char>>&board,int m,int n){
        if(idx==word.size()){
            return true;
        }
        for(int i=0;i<4;i++){
            int nx = x + dir[i].first;
            int ny = y + dir[i].second;
            if(nx>=0 && nx<m && ny>=0 && ny<n && board[nx][ny]==word[idx] && !vis[nx][ny]){
                vis[nx][ny]=1;
                if(find(nx,ny,idx+1,word,dir,vis,board,m,n))return true;
                vis[nx][ny]=0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m =board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<pair<int,int>>dir = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    vis[i][j]=1;
                    bool ans=find(i,j,1,word,dir,vis,board,m,n);
                    vis[i][j]=0;
                    if(ans){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};