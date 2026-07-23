class Solution {
public:
    int find(int target,vector<int>&nums,vector<int>&dp,int n){
        if(target<0)return 0;
        if(target==0)return 1;
        if(dp[target]!=-1)return dp[target];
        int ans=0;
        for(int x:nums){
            ans+=find(target-x,nums,dp,n);
        }
        return dp[target] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>dp(target+1,-1);
        return find(target,nums,dp,n);
    }
};