class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //find breaking point from right ie where decrease so that we can find next increse seq
        int n = nums.size();
        int i;
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        if(i==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int j=n-1;j>=0;j--){
            if(nums[i]<nums[j]){
                swap(nums[i],nums[j]);
                break;
            }
        }
        reverse(nums.begin()+i+1,nums.end());
        return;
    }
};