class Solution {
public:
    bool find(int ind,int target,vector<int>&nums,vector<vector<int>>&dp){
        if(target==0)return true;
        if(target<0)return false;
        if(ind==0)return nums[0]==target;
        if(dp[ind][target]!=-1)return dp[ind][target];
        bool pick = find(ind-1,target-nums[ind],nums,dp);
        bool notpick = find(ind-1,target,nums,dp);
        return dp[ind][target] = pick||notpick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total=0;
        for(int x:nums){
            total+=x;
        }
        if(total%2==1){
            return false;
        }
        else{
            int target = total/2;
            vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
            return find(n-1,target,nums,dp);
        }
    }
};