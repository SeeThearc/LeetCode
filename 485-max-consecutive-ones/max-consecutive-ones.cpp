class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int maxnum;
        int currmax=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                currmax++;
            }
            if(nums[i]!=1){
                maxnum=max(maxnum,currmax);
                currmax=0;
            }
        }
        maxnum=max(maxnum,currmax);
        return maxnum;
    }
};