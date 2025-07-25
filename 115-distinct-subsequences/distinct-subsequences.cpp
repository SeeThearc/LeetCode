class Solution {
public:
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        int mod=1e9+7;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                if(s[ind1-1]==t[ind2-1]){
                    dp[ind1][ind2] = (dp[ind1-1][ind2-1]+dp[ind1-1][ind2])%mod;
                }
                else{
                    dp[ind1][ind2]= dp[ind1-1][ind2];
                }
            }
        }
        return dp[n][m];
    }
};