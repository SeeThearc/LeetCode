class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adjLis(n+1);
        for(int i=0;i<times.size();i++){
            adjLis[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int time = temp.first;
            int node = temp.second;
            if(time>dist[node])continue;
            for(auto it:adjLis[node]){
                int v = it.first;
                int w = it.second;
                if(dist[node]+w<dist[v]){
                    dist[v]=dist[node]+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            maxi = max(maxi,dist[i]);
        }
        if(maxi==1e9)return -1;
        return maxi;
    }
};