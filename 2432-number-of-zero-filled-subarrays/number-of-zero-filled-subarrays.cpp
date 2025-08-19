class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res=0;
        long long c=0;
        for(auto x : nums){
            if(x==0){
                c++;
                res+=c;
            }
            else c=0;
        }
        return res;
    }
};