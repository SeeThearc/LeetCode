class Solution {
public:
    int find(vector<int>&nums,vector<int>&dp,int i,int n){
        if(i>=n)return 0;
        if(dp[i]!=-1)return dp[i];
        int rob = nums[i] + find(nums,dp,i+2,n);
        int norob = find(nums,dp,i+1,n);
        return dp[i] = max(rob,norob); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        return find(nums,dp,0,n);
    }
};