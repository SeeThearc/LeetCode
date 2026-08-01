class Solution {
public:
    int find(int i,int j,vector<vector<int>>&dp,vector<int>&nums){
        if(i==j){
            return nums[i];
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int takeleft = nums[i] - find(i+1,j,dp,nums);
        int takeright = nums[j] - find(i,j-1,dp,nums);
        return dp[i][j] = max(takeleft,takeright);
    }
    bool predictTheWinner(vector<int>& nums) {
        if(nums.size()==1)return true;
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        find(0,nums.size()-1,dp,nums);
        return dp[0][nums.size()-1]>=0;
    }
};