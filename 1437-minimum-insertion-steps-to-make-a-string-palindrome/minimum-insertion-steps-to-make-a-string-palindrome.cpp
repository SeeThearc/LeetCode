class Solution {
public:
    int minInsertions(string s) {
        int n=s.size();
        int ans=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=n;ind2++){
                if(s[ind1-1]==s[n-ind2]){
                    dp[ind1][ind2] = 1+ dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        return n-dp[n][n];
    }
};