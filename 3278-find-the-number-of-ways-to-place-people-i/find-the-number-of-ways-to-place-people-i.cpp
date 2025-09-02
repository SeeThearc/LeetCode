class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                auto a = points[i];
                auto b = points[j];
                if(a[0]<=b[0] && a[1]>=b[1]){
                    bool valid=true;
                    for(int k=0;k<n;k++){
                        if(k==i || k==j)continue;
                        auto p =points[k];
                        if(p[0]>=a[0] && p[0]<=b[0] && p[1]<=a[1] && p[1]>=b[1]){
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