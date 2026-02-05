class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>ss;
        for(int i=0;i<nums.size();i++){
            ss.insert(nums[i]);
        }
        return nums.size()==ss.size()?false:true;
    }
};