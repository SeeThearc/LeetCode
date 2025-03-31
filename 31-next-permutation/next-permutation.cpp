class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1){
            return;
        }
        int n=nums.size();
        int i;
        bool flag=false;
        for(i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                flag=true;
                break;
            }
        }
        if(flag==false){
            reverse(nums.begin(),nums.end());
            return;
        }
        int j;
        for(j=n-1;j>i;j--){
            if(nums[j]>nums[i]){
                break;
            }
        }
        swap(nums[i],nums[j]);
        reverse(nums.begin()+i+1,nums.end());
    }
};