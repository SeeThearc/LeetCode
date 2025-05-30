class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int>&a , const       vector<int>&b){
            return a[0]<b[0];
        });
        int start=intervals[0][0],end=intervals[0][1];
        vector<vector<int>>ans;
        int n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=end){
                end=max(end,intervals[i][1]);
            }
            else{
                vector<int>temp={start,end};
                ans.push_back(temp);
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        vector<int>temp1={start,end};
        ans.push_back(temp1);
        return ans;
    }
};