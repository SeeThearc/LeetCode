class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int>dp(n);
        int mini = prices[0];
        dp[0] = INT_MIN;
        for(int i=1;i<n;i++){
            dp[i] = max(dp[i-1],prices[i]-mini);
            mini = min(mini,prices[i]);
        }
        if(dp[n-1]<0)return 0;
        return dp[n-1];
    }
};