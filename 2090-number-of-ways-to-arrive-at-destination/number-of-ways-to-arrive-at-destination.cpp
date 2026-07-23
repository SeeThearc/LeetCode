using P = pair<long long, long long>;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adjlis(n);
        for(int i=0;i<(int)roads.size();i++){
            adjlis[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adjlis[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<P,vector<P>,greater<>>pq;
        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);
        ways[0]=1;
        int mod=1e9+7;
        dist[0]=0;
        pq.push({0,0});
        while(!pq.empty()){
            auto [we,node] = pq.top();
            pq.pop();
            if(we>dist[node])continue;
            for(int i=0;i<(int)adjlis[node].size();i++){
                int v = adjlis[node][i].first;
                int w = adjlis[node][i].second;
                long long newdist = we + w;
                if(newdist<dist[v]){
                    dist[v]=we + w;
                    ways[v] = ways[node];
                    pq.push({dist[v],v});
                }
                else if(newdist==dist[v]){
                    ways[v]%=mod;
                    ways[node]%=mod;
                    ways[v]+=ways[node];
                }
            }
        }
        return ways[n-1] % mod;
    }
};