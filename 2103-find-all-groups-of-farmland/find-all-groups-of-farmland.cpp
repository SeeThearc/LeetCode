class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1){
                    vector<int>temp;
                    int mx=i,my=j;
                    while(mx+1<m && land[mx+1][j]==1)mx++;
                    while(my+1<n && land[i][my+1]==1)my++;
                    for(int k=i;k<=mx;k++){
                        for(int p=j;p<=my;p++){
                            land[k][p]=0;
                        }
                    }
                    ans.push_back({i,j,mx,my});
                }
            }
        }
        return ans;
    }
};