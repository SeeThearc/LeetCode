class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[0][i]=matrix[0][i];
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                int ans;
                if(j==0){
                    ans=min(dp[i-1][j],dp[i-1][j+1]);
                }
                else if(j==n-1){
                    ans=min(dp[i-1][j],dp[i-1][j-1]);
                }
                else{
                    ans=min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]));
                }
                dp[i][j]=ans+matrix[i][j];
            }
        }
        int minn=INT_MAX;
        for(int j=0;j<n;j++){
            minn=min(minn,dp[m-1][j]);
        }
        return minn;
    }
};