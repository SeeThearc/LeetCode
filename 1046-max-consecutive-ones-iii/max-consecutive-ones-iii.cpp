class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0,right=0;
        int c0=0;
        int n = nums.size();
        int maxn=0;
        while(right<n){
            if(nums[right]==1){
                right++;
                maxn=max(maxn,right-left);
            }
            else if(c0<k){
                c0++;
                right++;
                maxn=max(maxn,right-left);
            }
            else{
                if(nums[left]==1)left++;
                else{
                    c0--;
                    left++;
                }
            }
        }
        return maxn;
    }
};