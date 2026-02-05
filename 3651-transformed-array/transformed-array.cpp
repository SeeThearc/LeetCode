class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int i=0,j=0;
        int n = nums.size();
        vector<int>res;
        while(i<n){
            j=i;
            if(nums[j]==0){
                res.push_back(nums[j]);
                i++;
            }
            else if(nums[j]>0){
                j = j + nums[j];
                j=j%n;
                res.push_back(nums[j]);
                i++;
            }
            else{
                j = j - abs(nums[j]);
                while(j<0){
                    j=j+n;
                }
                res.push_back(nums[j]);
                i++;
            }
        }
        return res;
    }
};