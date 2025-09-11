class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>adjLis(numCourses);
        vector<int>indegree(numCourses,0);
        for(int i=0;i<n;i++){
            adjLis[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        vector<int>vis(numCourses,0);
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                vis[i]=1;
            }
        }
        vector<int>ans;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            ans.push_back(it);
            for(int i=0;i<adjLis[it].size();i++){
                indegree[adjLis[it][i]]--;
            }
            for(int i=0;i<numCourses;i++){
                if(!vis[i] && indegree[i]==0){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        return ans.size()==numCourses;
    }
};