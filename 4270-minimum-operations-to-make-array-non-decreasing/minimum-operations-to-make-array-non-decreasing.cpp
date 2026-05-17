class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long x=0;
        int n = nums.size();
        long long mv=nums[0];
        for(int i=1;i<n;i++){
            if(x+nums[i]<mv){
                x+=abs(mv-(nums[i]+x));
                mv=nums[i]+x;
            }
            else{
                mv=x+nums[i];
            }
        }
        return x;
    }
};