class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mpp;
        int presum=0,count=0;
        int n = nums.size();
        mpp[0]=1;
        for(int i=0;i<n;i++){
            presum+=nums[i];
            int rem = presum-k;
            count+=mpp[rem];
            mpp[presum]++;
        }
        return count;
    }
};