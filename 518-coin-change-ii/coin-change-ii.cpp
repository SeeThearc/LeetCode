class Solution {
public:
    int find(int ind,int amo,vector<int>&coins,vector<vector<int>>&dp){
        if(amo<0)return 0;
        if(ind==0){
            return (amo%coins[0]==0);
        }
        if(dp[ind][amo]!=-1)return dp[ind][amo];
        int notpick = find(ind-1,amo,coins,dp);
        int pick = find(ind,amo-coins[ind],coins,dp);
        return dp[ind][amo] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return find(n-1,amount,coins,dp);
    }
};