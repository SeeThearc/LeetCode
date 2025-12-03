class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n = nums.size();
        if(k==0)return n;
        sort(nums.begin(),nums.end());
        int thresh = nums[n-k];
        int c=0;
        for(int x:nums){
            if(x<thresh)c++;
        }
        return c;
    }
};