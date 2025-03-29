class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int currnum;
        int i=0;
        while(i!=n-1){
            if(nums[i]==nums[i+1]){
                i=i+2;
            }
            else{
                currnum=nums[i];
                break;
            }
        }
        return currnum;
    }
};