class Solution {
public:
    int find(int ind,int canbuy,int cool,int n,vector<int>&prices,vector<vector<int>>&dp){
        if(ind>=n)return 0;
        if(dp[ind][canbuy]!=-1)return dp[ind][canbuy];
        // if(cool){
        //     return find(ind+1,canbuy,0,n,prices,dp);
        // }
        int profit=0;
        if(canbuy){
            profit = max(0+find(ind+1,1,0,n,prices,dp),-prices[ind]+find(ind+1,0,0,n,prices,dp));
        }
        else{
            profit = max(0+find(ind+1,0,0,n,prices,dp),prices[ind]+find(ind+2,1,1,n,prices,dp));
        }
        return dp[ind][canbuy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return find(0,1,0,n,prices,dp);
    }
};