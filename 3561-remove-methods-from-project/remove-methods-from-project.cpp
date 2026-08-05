class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adjlis(n);
        for(int i=0;i<(int)invocations.size();i++){
            adjlis[invocations[i][0]].push_back(invocations[i][1]);
        }
        //map<int,int>mpp;
        vector<int>vis(n,0);
        queue<int>q;
        vis[k]=1;
        q.push(k);
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            //mpp[node]=1;
            for(int i=0;i<(int)adjlis[node].size();i++){
                if(!vis[adjlis[node][i]]){
                    vis[adjlis[node][i]]=1;
                    q.push(adjlis[node][i]);
                }
            }
        }
        bool all=false;
        for(auto e:invocations){
            if(!vis[e[0]] && vis[e[1]]){
                all=true;
                break;
            }
        }
        vector<int>ans;
        if(all){
            for(int i=0;i<n;i++)ans.push_back(i);
        }
        else{
            for(int i=0;i<n;i++){
                if(!vis[i])ans.push_back(i);
            }
        }
        return ans;
    }
};