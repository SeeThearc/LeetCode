class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0;
        long long tot=0;
        int ans=0;
        for(int r=0;r<nums.size();r++){
            tot+=nums[r];
            while((long long)(r-l+1)*nums[r]-tot>k){
                tot-=nums[l];
                l++;
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};