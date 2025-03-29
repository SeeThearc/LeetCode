class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int unique=0;
        if(nums.size()==1){
            return 1;
        }
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]!=nums[i+1]){
                nums[unique]=nums[i];
                unique++;
            }
        }
        nums[unique]=nums[n-1];
        unique++;
        return unique;
    }
};