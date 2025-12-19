class Solution {
public:
    int helper(int n,vector<int>&dp,vector<int>&nums){
        if(n==0)return nums[0];
        if(n==1)return max(nums[1],nums[0]);
        if(dp[n]!=-1)return dp[n];
        int back2 = nums[n] + helper(n-2,dp,nums);
        int back1 = helper(n-1,dp,nums);
        dp[n] = max(back2,back1);
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>dp(n,-1);
        return helper(n-1,dp,nums);
    }
};