class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int targ) {
        int n=nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum-abs(targ) < 0 || (sum-targ)%2!=0){
            return 0;
        }
        // sum p - sum n == targ
        // sum p + sum n == sum
        // so 2*sum p = targ + sum
        int target = (sum+targ)/2;
        int mod = 1e9 + 7;
        vector<vector<int>>dp(n,vector<int>(target+1,0));
        if(nums[0]==0){
            dp[0][0]=2;
        }
        else{
            dp[0][0]=1;
        }
        if(nums[0]!=0 && nums[0]<=target){
            dp[0][nums[0]]=1;
        }
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=target;tar++){
                int notTaken = dp[ind-1][tar];
                int taken = 0;
                if(nums[ind]<=tar){
                    taken = dp[ind-1][tar-nums[ind]];
                }
                dp[ind][tar] = (notTaken + taken)%mod ; 
            }
        }
        return dp[n-1][target];
    }
};