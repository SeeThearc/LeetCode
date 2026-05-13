    bool comp(vector<int>a,vector<int>b){
            return (a[1]-a[0])>(b[1]-b[0]);
    }
class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),comp);
        int mini = tasks[0][1];
        int ans=tasks[0][1];
        mini-=tasks[0][0];
        int n = tasks.size();
        // for(int i=0;i<n;i++){
        //     cout<<tasks[i][0]<<" "<<tasks[i][1]<<endl;
        // }
        for(int i=1;i<n;i++){
            if(mini>=tasks[i][1]){
                mini-=tasks[i][0];
            }
            else{
                ans+=(tasks[i][1]-mini);
                mini=tasks[i][1];
                mini-=tasks[i][0];
            }
            // cout<<"Task"<<i<<" "<<ans<<endl;
        }
        return ans;
    }
};