class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<i+1;j++){
                if(i==0 && j==0){
                    dp[i][j]=triangle[i][j];
                    continue;
                }
                int up,upleft,ans;
                if(i==j){
                    ans=dp[i-1][j-1];
                }
                else if(i>0 && j>0){
                    up=dp[i-1][j];
                    upleft=dp[i-1][j-1];
                    ans=min(up,upleft);
                }
                else if(i>0){
                    up=dp[i-1][j];
                    ans=up;
                }
                dp[i][j]=triangle[i][j]+ans;
            }
        }
        int minn=INT_MAX;
        for(int j=0;j<m;j++){
            minn=min(minn,dp[m-1][j]);
        }
        return minn;
    }
};