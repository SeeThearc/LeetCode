class Solution {
public:
    int findMaxK(vector<int>& nums) {
        map<int,int>mpp;
        int n = nums.size();
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(nums[i]>0){
                if(mpp[-1 * nums[i]]){
                    maxi = max(maxi,nums[i]);
                }
            }
            else{
                if(mpp[-1 * nums[i]]){
                    maxi = max(maxi,-1*nums[i]);
                }
            }
            mpp[nums[i]]=1;
        }
        return maxi;
    }
};