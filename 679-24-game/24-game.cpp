class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double>nums(cards.begin(),cards.end());
        return solve(nums);
    }
    const double eps = 1e-3;
    bool solve(vector<double>&nums){
        int n = nums.size();
        if(n==1){
            return fabs(nums[0]-24)<eps;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                vector<double>nextnums;
                for(int k=0;k<n;k++){
                    if(k!=i && k!=j){
                        nextnums.push_back(nums[k]);
                    }
                }

                for(auto val : compute(nums[i],nums[j])){
                    nextnums.push_back(val);
                    if(solve(nextnums))return true;
                    nextnums.pop_back();
                }
            }
        }
        return false;
    }
    vector<double>compute(double a,double b){
        vector<double>res;
        res.push_back(a+b);
        res.push_back(a-b);
        res.push_back(b-a);
        res.push_back(a*b);
        if(b!=0)res.push_back(a/b);
        if(a!=0)res.push_back(b/a);
        return res;
    }
};