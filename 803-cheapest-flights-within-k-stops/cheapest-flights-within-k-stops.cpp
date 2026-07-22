class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adjlis(n);
        for(int i=0;i<(int)flights.size();i++){
            adjlis[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<>>pq;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        pq.push({{0,src},0});
        // stops node distance till that node from src
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            auto stops = it.first.first;
            auto node = it.first.second;
            auto d = it.second;
            if(stops>k)continue;
            for(auto i:adjlis[node]){
                auto v = i.first;
                auto di = i.second;
                if(d+di<dist[v]){
                    dist[v] = d + di;
                    pq.push({{stops+1,v},dist[v]});
                }
            }
        }
        return (dist[dst]==INT_MAX?-1:dist[dst]);
    }
};