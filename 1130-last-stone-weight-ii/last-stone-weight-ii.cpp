class Solution {
public:
    int find(int i,int sum,vector<int>&stones,vector<vector<int>>&dp,int n,int total){
        if(i==n)return abs((total-sum)-sum);
        if(dp[i][sum]!=-1)return dp[i][sum];
        int pick = find(i+1,sum+stones[i],stones,dp,n,total);
        int notpick = find(i+1,sum,stones,dp,n,total);
        return dp[i][sum] = min(pick,notpick);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total=0;
        for(int x:stones)total+=x;
        vector<vector<int>>dp(n,vector<int>(total,-1));
        return find(0,0,stones,dp,n,total);
    }
};