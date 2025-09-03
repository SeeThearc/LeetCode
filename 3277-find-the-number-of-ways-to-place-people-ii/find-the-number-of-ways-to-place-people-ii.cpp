class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        long long ans=0;
        sort(points.begin(), points.end(), [](auto &a, auto &b) {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        for(int i=0;i<n;i++){
            int xa = points[i][0];
            int ya = points[i][1];
            for(int j=i+1;j<n;j++){
                if(i==j)continue;
                int xb = points[j][0];
                int yb = points[j][1];
                if(xa<=xb && ya>=yb){
                    bool valid=true;
                    for(int k=i+1;k<j;k++){
                        //if(k==i || k==j)continue;
                        int x = points[k][0];
                        int y = points[k][1];
                        if(xa<=x && x<=xb && yb<=y && y<=ya){
                            valid=false;
                            break;
                        }
                    }
                    if(valid)ans++;
                }
            }
        }
        return ans;
    }
};