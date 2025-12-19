class Solution {
public:
    int helper(int n,vector<int>&dp){
        if(n<1)return 0;
        if(dp[n]!=-1)return dp[n];
        if(n==1)return 1;
        if(n==2)return 2;
        dp[n] = helper(n-1,dp) + helper(n-2,dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return helper(n,dp);
    }
};