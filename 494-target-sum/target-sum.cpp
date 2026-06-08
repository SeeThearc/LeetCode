class Solution {
public:
    int find(int ind,int tar,vector<int>&nums,vector<vector<int>>&dp){
        if(tar<0)return 0;
        if(ind==0){
            if(tar==0 && nums[ind]==0)return 2;
            if(tar==0 || nums[ind]==tar)return 1;
            return 0;
        }
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        int notpick = find(ind-1,tar,nums,dp);
        int pick = find(ind-1,tar-nums[ind],nums,dp);
        return dp[ind][tar] = pick+notpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total=0;
        for(int x:nums)total+=x;
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
        if(abs(target)>total)return 0;
        if((total-target)%2==1)return 0;
        int tar = (total-target)/2;
        return find(n-1,tar,nums,dp);
    }
};