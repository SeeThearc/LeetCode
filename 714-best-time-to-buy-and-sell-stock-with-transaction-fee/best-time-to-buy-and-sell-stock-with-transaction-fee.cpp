class Solution {
public:
    int find(int ind,int canbuy,int n,vector<int>&prices,vector<vector<int>>&dp,int fee){
        if(ind==n)return 0;
        if(dp[ind][canbuy]!=-1)return dp[ind][canbuy];
        int profit = 0;
        if(canbuy){
            profit = max(0+find(ind+1,1,n,prices,dp,fee),-prices[ind]-fee+find(ind+1,0,n,prices,dp,fee));
        }
        else{
            profit = max(0+find(ind+1,0,n,prices,dp,fee),prices[ind]+find(ind+1,1,n,prices,dp,fee));
        }
        return dp[ind][canbuy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return find(0,1,n,prices,dp,fee);
    }
};