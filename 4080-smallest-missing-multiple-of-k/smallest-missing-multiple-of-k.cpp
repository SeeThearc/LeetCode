class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int,bool>mpp;
        for(int x:nums){
            mpp[x]=true;
        }
        bool found=false;
        int j=k;
        while(!found){
            if(!mpp[j])return j;
            else j=j+k;
        }
        return -1;
    }
};