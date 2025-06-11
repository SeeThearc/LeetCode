class Solution {
public:
    int solve(vector<int>nums){
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int pick=0,notpick=0;
            pick+=nums[i];
            if(i>1){
                pick+=dp[i-2];
            }
            notpick+=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==0)return 0;
        vector<int>arr1;
        vector<int>arr2;
        for(int i=0;i<n;i++){
            if(i!=0){
                arr1.push_back(nums[i]);
            }
            if(i!=n-1){
                arr2.push_back(nums[i]);
            }
        }
        int ans1=solve(arr1);
        int ans2=solve(arr2);
        return(max(ans1,ans2));
    }
};