class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,INT_MAX));
        for(int i=0;i<m;i++){
            int si = triangle[i].size();
            for(int j=0;j<si;j++){
                if(i==0 && j==0){
                    dp[i][j] = triangle[i][j];
                    continue;
                }
                int val1=INT_MAX,val2=INT_MAX;
                if(j>=1){
                    val1 = dp[i-1][j-1];
                }
                val2 = dp[i-1][j];
                int sum = min(val1,val2);
                sum+=triangle[i][j];
                dp[i][j] = sum;
            }
        }
        int mini = INT_MAX;
        for(int x:dp[m-1]){
            mini = min(mini,x);
        }
        return mini;
    }
};