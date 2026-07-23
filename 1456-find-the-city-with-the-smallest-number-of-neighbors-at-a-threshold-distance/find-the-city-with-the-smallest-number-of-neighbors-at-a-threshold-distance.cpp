class Solution {
public:
    int dji(int src,vector<vector<pair<int,int>>>&adjlis,int n,int thresh){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        vector<int>dist(n,INT_MAX);
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            auto [we,node] = pq.top();
            pq.pop();
            if(we>dist[node])continue;
            if(we>thresh)break;
            for(int i=0;i<(int)adjlis[node].size();i++){
                int v = adjlis[node][i].first;
                int w = adjlis[node][i].second;
                if(we+w<dist[v] && we+w<=thresh){
                    dist[v] = we + w;
                    pq.push({dist[v],v});
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(dist[i]!=INT_MAX)c++;
        }
        return c;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int ans=0;
        int mincity = INT_MAX;
        vector<vector<pair<int,int>>>adjlis(n);
        for(int i=0;i<(int)edges.size();i++){
            adjlis[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adjlis[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        for(int i=0;i<n;i++){
            int c = dji(i,adjlis,n,distanceThreshold);
            if(c<mincity){
                mincity = c;
                ans=i;
            }
            else if(c==mincity){
                if(i>ans)ans=i;
            }
        }
        return ans;
    }
};