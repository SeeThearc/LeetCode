class Solution {
public:
    void find(int idx,int target,vector<int>&candidates,vector<vector<int>>&result,vector<int>&path){
        if(target==0){
            result.push_back(path);
            return;
        }
        for(int i = idx;i<candidates.size();i++){
            if(candidates[i]<=target){
                path.push_back(candidates[i]);
                find(i,target-candidates[i],candidates,result,path);
                path.pop_back();
            }
            
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>path;
        find(0,target,candidates,result,path);
        return result;
    }
};