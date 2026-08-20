class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1,arr2;
        if(nums.size()<=2)return nums;
        int it1=0,it2=0;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        int n = nums.size();
        for(int i=2;i<n;i++){
            if(arr1[it1]>arr2[it2]){
                arr1.push_back(nums[i]);
                it1++;
            }
            else{
                arr2.push_back(nums[i]);
                it2++;
            }
        }
        vector<int>ans = arr1;
        ans.insert(ans.end(),arr2.begin(),arr2.end());
        return ans;
    }
};