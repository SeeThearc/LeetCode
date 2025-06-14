class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[i][j];
                    continue;
                }
                int up=-1,left=-1,fin=-1;
                if(i>0){
                    up=dp[i-1][j];
                }
                if(j>0){
                    left=dp[i][j-1];
                }
                if(up==-1){
                    fin=left;
                }
                else if(left==-1){
                    fin=up;
                }
                else{
                    fin=min(up,left);
                }
                dp[i][j]=fin+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};