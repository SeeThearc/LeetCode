class Solution {
public:
    int find(int i,int n,vector<int>&nums,vector<int>&dp){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int pick = nums[i] + find(i+2,n,nums,dp);
        int nopick = find(i+1,n,nums,dp);
        return dp[i] = max(pick,nopick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        return max(find(0,n-1,nums,dp1),find(1,n,nums,dp2));
    }
};