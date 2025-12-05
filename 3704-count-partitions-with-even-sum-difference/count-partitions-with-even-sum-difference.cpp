class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for(int x:nums){
            total+=x;
        }
        int left=0,right;
        int c=0;
        for(int i=0;i<n-1;i++){
            left+=nums[i];
            right=total-left;
            if((left-right)%2==0)c++;
        }
        return c;
    }
};