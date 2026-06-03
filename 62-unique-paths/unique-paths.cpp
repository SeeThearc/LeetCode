class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>grid(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    grid[i][j] = 1;
                    continue;
                }
                int sum1=0,sum2=0;
                if(i>0){
                    sum1 = grid[i-1][j];
                }
                if(j>0){
                    sum2 = grid[i][j-1];
                }
                grid[i][j] = sum1+sum2;
            }
        }
        return grid[m-1][n-1];
    }
};