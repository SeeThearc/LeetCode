class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        int maxi=INT_MIN;
        int n = nums.size();
        for(int i=0;i<n;i++){
            maxi = max(maxi,nums[i]);
        }
        for(int x:nums){
            sum+=(maxi-x);
        }
        return sum;
    }
};