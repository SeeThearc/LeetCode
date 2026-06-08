class Solution {
public:
    int find(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(amount<0)return 1e9;
        if(amount==0)return 0;
        if(ind==0){
            if(amount%coins[0]==0)return amount/coins[0];
            else return 1e9;
        }
        if(dp[ind][amount]!=INT_MAX)return dp[ind][amount];
        int notpick = find(ind-1,amount,coins,dp);
        int pick = 1 + find(ind,amount-coins[ind],coins,dp);
        return dp[ind][amount] = min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)return 0;
        int n = coins.size();
        if(n==1){
            if(amount%coins[0]==0)return amount/coins[0];
            else return -1;
        }
        vector<vector<int>>dp(n,vector<int>(amount+1,INT_MAX));
        int ans = find(n-1,amount,coins,dp);
        if(ans==0 || ans>=1e9)return -1;
        return ans;
    }
};