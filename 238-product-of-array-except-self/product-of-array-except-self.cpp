class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int total=1;
        int c0=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                c0++;
            }
            else{
                total*=nums[i];
            }
        }
        if(c0>1){
            vector<int> a(n,0);
            return a;
        }
        vector<int>ans;
        if(c0==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    ans.push_back(total);
                }
                else{
                    ans.push_back(0);
                }
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    ans.push_back(total);
                }
                else{
                    ans.push_back(total/nums[i]);
                }
            }
        }
        return ans;
    }
};