class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int major=nums.size()/3;
        vector<int>ans;
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        for(auto it:mpp){
            if(it.second>major){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};