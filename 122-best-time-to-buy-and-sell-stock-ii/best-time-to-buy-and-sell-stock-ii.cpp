class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        dp[n][0]=dp[n][1]=0;
        //buy ==0 can buy and buy == 1 can not buy ie already buyed
        int profit=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                if(buy==0){
                    profit=max(dp[ind+1][0],-prices[ind]+dp[ind+1][1]);
                }
                else{
                    profit=max(dp[ind+1][1],prices[ind]+dp[ind+1][0]);
                }
                dp[ind][buy] = profit;
            }
        }
        return dp[0][0];
    }
};