class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1=0,prev2=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int curr = max(prev2+nums[i],prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};