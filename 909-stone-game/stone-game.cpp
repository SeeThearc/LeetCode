class Solution {
public:
    bool find(int i,int j,vector<int>&piles,vector<vector<int>>&dp){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int takeleft = piles[i] - find(i+1,j,piles,dp);
        int takeright = piles[i] - find(i,j-1,piles,dp);
        return dp[i][j] = max(takeleft,takeright);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum=0;
        for(int x:piles)sum+=x;
        vector<vector<int>>dp(n,vector<int>(sum,-1));
        return find(0,n-1,piles,dp);
    }
};