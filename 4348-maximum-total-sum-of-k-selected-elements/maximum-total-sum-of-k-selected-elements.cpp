class Solution {
public:
    static bool comparator(const int&a,const int&b){
        return a>b;
    }
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),comparator);
        long long sum=0;
        for(int i=0;i<k;i++){
            if(mul>0){
                sum+=(1LL * nums[i]*mul);
                mul--;
            }
            else{
                sum+=nums[i];
            }
        }
        return sum;
    }
};