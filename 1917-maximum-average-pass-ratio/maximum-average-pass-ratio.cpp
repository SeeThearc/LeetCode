class Solution {
public:
    auto gain(int a,int b){
        return (double)(a+1)/(b+1) - (double)a/b;
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        priority_queue<pair<double,pair<int,int>>>pq;
        for(auto &c:classes){
            pq.push({gain(c[0],c[1]),{c[0],c[1]}});
        }
        while(extraStudents>0){
            auto tp = pq.top();
            pq.pop();
            int a = tp.second.first;
            int b = tp.second.second;
            a++;
            b++;
            pq.push({gain(a,b),{a,b}});
            extraStudents--;
        }
        double sum = 0;
        for(int i=0;i<classes.size();i++){
            auto tp = pq.top();
            pq.pop();
            int a = tp.second.first;
            int b = tp.second.second;
            sum += (double)a/b;
        }
        return (double)sum/n;
    }
};