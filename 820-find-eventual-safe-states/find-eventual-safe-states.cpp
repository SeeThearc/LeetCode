class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adjLis(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adjLis[graph[i][j]].push_back(i);
            }
        }
        vector<int>inDegree(n,0);
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(auto it:adjLis[i]){
                inDegree[it]++;
            }
        }
        for(int i=0;i<n;i++){
            if(inDegree[i]==0)q.push(i);
        }
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto it:adjLis[temp]){
                inDegree[it]--;
                if(inDegree[it]==0)q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};