class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // vector<pair<int,int>>adj(n);
        // for(int i=0;i<(int)flights.size();i++){
        //     adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        // }
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        for(int it=0;it<=k;it++){
            auto temp = dist;
            for(auto it:flights){
                int u = it[0];
                int v = it[1];
                int w = it[2];
                if(dist[u]!=INT_MAX && dist[u]+w<temp[v]){
                    temp[v] = dist[u]+w;
                }
            }
            dist=temp;
        }
        return (dist[dst]!=INT_MAX?dist[dst]:-1);
    }
};