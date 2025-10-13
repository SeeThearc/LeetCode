class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int presum=0;
        map<int,int>mpp;
        int c=0;
        mpp[0]=1;
        for(int i=0;i<nums.size();i++){
            presum+=nums[i];
            int rem = presum-k;
            c+=mpp[rem];
            mpp[presum]++;
        }
        return c;
    }
};