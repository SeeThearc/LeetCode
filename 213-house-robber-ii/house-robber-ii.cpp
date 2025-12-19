class Solution {
public:
    int helper(int n,vector<int>&dp,vector<int>&nums){
        if(n==0)return nums[0];
        if(n==1)return max(nums[0],nums[1]);
        if(dp[n]!=-1)return dp[n];
        int back1 = helper(n-1,dp,nums);
        int back2 = nums[n]+helper(n-2,dp,nums);
        return dp[n] = max(back1,back2);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        vector<int>arr1,arr2;
        for(int i=0;i<n;i++){
            if(i==0){
                arr1.push_back(nums[i]);
                continue;
            }
            if(i==n-1){
                arr2.push_back(nums[i]);
                continue;
            }
            arr1.push_back(nums[i]);
            arr2.push_back(nums[i]);
        }
        int a = helper(arr1.size()-1,dp1,arr1);
        int b = helper(arr2.size()-1,dp2,arr2);
        return max(a,b);
    }
};