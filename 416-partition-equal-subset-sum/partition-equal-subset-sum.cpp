class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2==1){
            return false;
        }
        int k=sum/2;
        vector<vector<int>>dp(n,vector<int>(k+1,false));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        if(nums[0]<=k){
            dp[0][nums[0]]=true;
        }
        for(int ind=1;ind<n;ind++){
            for(int tar=1;tar<=k;tar++){
                bool notTaken = dp[ind-1][tar];
                bool taken = false;
                if(nums[ind]<=tar){
                    taken = dp[ind-1][tar-nums[ind]];
                }
                dp[ind][tar] = notTaken || taken;
            }
        }
        return dp[n-1][k];
    }
};