class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool>mpp;
        for(int x:nums){
            if(!mpp[x]){
                mpp[x]=true;
            }
            else{
                return true;
            }
        }
        return false;
    }
};