class Solution {
public:
    int maxdif(int n){
        int maxi=INT_MIN;
        int mini=INT_MAX;
        while(n>0){
            int dig = n%10;
            mini = min(mini,dig);
            maxi = max(maxi,dig);
            n/=10;
        }
        return maxi-mini;
    }
    int maxDigitRange(vector<int>& nums) {
        int n = nums.size();
        map<int,int>freq;
        map<int,int>mpp;
        int maxi=0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            int v = maxdif(nums[i]);
            maxi = max(maxi,v);
            mpp[nums[i]]=v;
        }
        int sum=0;
        for(auto it:mpp){
            if(it.second==maxi){
                sum+=(it.first*freq[it.first]);
            }
        }
        return sum;
    }
};