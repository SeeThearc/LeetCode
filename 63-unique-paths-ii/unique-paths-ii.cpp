class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>>grid(m,vector<int>(n,0));
        if(obstacleGrid[0][0]==1)return 0;
        if(m==1 && n==1)return 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    grid[i][j]=1;
                    continue;
                }
                int sum1=0,sum2=0;
                if(obstacleGrid[i][j]==0){
                    if(i>0 && obstacleGrid[i-1][j]!=1){
                        sum1 = grid[i-1][j];
                    }
                    if(j>0 && obstacleGrid[i][j-1]!=1){
                        sum2 = grid[i][j-1];
                    }
                    grid[i][j] = sum1+sum2;
                }
            }
        }
        return grid[m-1][n-1];
    }
};