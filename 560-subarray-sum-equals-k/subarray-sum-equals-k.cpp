class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int ans=0;
        int total=0;
        mp[0]=1;
        for(int i=0;i<n;i++){
            total+=nums[i];
            int rem = total-k;
            ans+=mp[rem];
            mp[total]++;
        }
        return ans;
    }
};