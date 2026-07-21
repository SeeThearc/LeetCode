class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<(int)times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto m = pq.top();
            pq.pop();
            int node = m.second;
            int we = m.first;
            if(we>dist[node])continue;
            for(auto it:adj[node]){
                int v = it.first;
                int w = it.second;
                if(dist[node]+w<dist[v]){
                    dist[v]=dist[node]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int ans=-1;
        int c=0;
        for(int i=1;i<(int)dist.size();i++){
            if(dist[i]==INT_MAX)continue;
            ans=max(ans,dist[i]);
            c++;
        }
        return (c==n?ans:-1);
    }
};