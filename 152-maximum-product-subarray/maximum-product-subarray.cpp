class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minprod=nums[0],maxprod=nums[0];
        int result=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0)swap(minprod,maxprod);
            maxprod = max(nums[i],maxprod*nums[i]);
            minprod = min(nums[i],minprod*nums[i]);
            result = max(result,maxprod);
        }
        return result;
    }
};