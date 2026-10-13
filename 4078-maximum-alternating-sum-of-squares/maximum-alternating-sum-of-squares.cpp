class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](const int &a,const int &b){
            return abs(a)>abs(b);
        });
        int n = nums.size();
        long long total=0;
        int i=0;
        while(i<n/2){
            total+=(nums[i]*nums[i]);
            i++;
        }
        if(n%2==1){
            total+=(nums[i]*nums[i]);
            i++;
        }
        while(i<n){
            total-=(nums[i]*nums[i]);
            i++;
        }
        return total;
    }
};