class Solution {
public:
    void find(int st,vector<int>&nums,vector<vector<int>>&ans,vector<int>&path,int n){
        ans.push_back(path);
        for(int i=st;i<n;i++){
            path.push_back(nums[i]);
            find(i+1,nums,ans,path,n);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        vector<int>path;
        find(0,nums,ans,path,n);
        return ans;
    }
};