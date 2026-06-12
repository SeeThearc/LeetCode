class Solution {
public:
    int find(int ind,int canbuy,int tran,int n,int k,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(ind==n)return 0;
        if(tran>k)return 0;
        if(dp[ind][canbuy][tran]!=-1)return dp[ind][canbuy][tran];
        int profit = 0;
        if(canbuy){
            profit = max(0+find(ind+1,1,tran,n,k,prices,dp),-prices[ind]+find(ind+1,0,tran+1,n,k,prices,dp));
        } 
        else{
            profit = max(0+find(ind+1,0,tran,n,k,prices,dp),prices[ind]+find(ind+1,1,tran,n,k,prices,dp));
        }
        return dp[ind][canbuy][tran] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return find(0,1,0,n,k,prices,dp);
    }
};