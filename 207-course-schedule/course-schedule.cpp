class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>>adjLis(numCourses);
        vector<int>inDegree(numCourses);
        for(int i=0;i<n;i++){
            adjLis[prerequisites[i][0]].push_back(prerequisites[i][1]);
            inDegree[prerequisites[i][1]]++;
        }
        vector<int>vis(numCourses,0);
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(inDegree[i]==0){
                q.push(i);
                vis[i]=1;
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            ans.push_back(temp);
            for(auto it:adjLis[temp]){
                inDegree[it]--;
            }
            for(int i=0;i<numCourses;i++){
                if(!vis[i] && inDegree[i]==0){
                    q.push(i);
                    vis[i]=1;
                }
            }
        }
        if(ans.size()==numCourses)return true;
        return false;
    }
};