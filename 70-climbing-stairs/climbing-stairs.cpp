class Solution {
public:
    int find(vector<int>&dp,int i){
        if(i==0 || i==1)return 1;
        if(dp[i]!=-1)return dp[i];
        dp[i] = find(dp,i-1)+find(dp,i-2);
        return dp[i];
    }
    int climbStairs(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        vector<int>dp(n+1,-1);
        find(dp,n);
        return dp[n];
    }
};