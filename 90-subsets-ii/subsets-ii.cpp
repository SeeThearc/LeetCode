class Solution {
public:
    void find(int sta,vector<int>&path,set<vector<int>>&st,vector<int>&nums,int n){
        st.insert(path);
        for(int i=sta;i<n;i++){
            path.push_back(nums[i]);
            find(i+1,path,st,nums,n);
            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        vector<int>path;
        int n = nums.size();
        find(0,path,st,nums,n);
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};