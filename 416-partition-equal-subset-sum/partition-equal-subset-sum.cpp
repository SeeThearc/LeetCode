class Solution {
public:
    bool find(int i,int target,vector<int>&nums,vector<vector<int>>&dp,int n){
        if(target==0)return true;
        if(target<0)return false;
        if(i==n)return false;
        if(dp[i][target]!=-1)return dp[i][target];
        bool pick = find(i+1,target-nums[i],nums,dp,n);
        bool notpick = find(i+1,target,nums,dp,n);
        return dp[i][target] = pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total=0;
        for(int x:nums){
            total+=x;
        }
        if(total%2==1)return false;
        int target = total/2;
        vector<vector<int>>dp(n,vector<int>(target+1,-1));
        return find(0,target,nums,dp,n);
    }
};