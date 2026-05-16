class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int left=INT_MIN,right=INT_MIN;
        vector<int>r(n,INT_MIN);
        for(int i=n-1;i>=0;i--){
            r[i] = max(r[i],right);
            right = max(right,nums[i]);
        }
        for(int i=0;i<n;i++)cout<<r[i]<<" ";
        for(int i=0;i<n;i++){
            if((nums[i]>left)){
                ans.push_back(nums[i]);
                left=nums[i];
            }
            else if(nums[i]>r[i]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};