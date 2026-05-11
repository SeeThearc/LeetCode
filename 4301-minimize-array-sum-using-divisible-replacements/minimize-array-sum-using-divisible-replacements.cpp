class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        int n = nums.size();
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi =max(maxi,nums[i]); 
        }
        vector<bool>flag(maxi+1,false);
        for(int i=0;i<nums.size();i++){
            flag[nums[i]]=true;
        }
        if(flag[1])return n;
        vector<int>div=nums;
        long long total=0;
        for(auto x:nums){
            int best=x;
            for(int d=1;d*d<=x;d++){
                if(x%d==0){
                    int x1 = d;
                    int x2 = x/d;
                    if(flag[x1]){
                        best = min(best,x1);
                    }
                    if(flag[x2]){
                        best = min(best,x2);
                    }
                }
            }
            total+=best;
        }
        return total;
    }
};