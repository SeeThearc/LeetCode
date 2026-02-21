class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        bool r=false;
        for(int i=0;i<n;i++){
            if(nums[i]>nums[(i+1)%n] && r)return false;
            if(nums[i]>nums[(i+1)%n]){
                r=true;
                continue;
            }
        }
        return true;
    }
};