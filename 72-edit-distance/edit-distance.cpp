class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int i=0;i<=n1;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=n2;i++){
            dp[0][i]=i;
        }
        for(int ind1=1;ind1<=n1;ind1++){
            for(int ind2=1;ind2<=n2;ind2++){
                if(word1[ind1-1]==word2[ind2-1]){
                    dp[ind1][ind2]=dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2]=1+min(dp[ind1-1][ind2-1],min(dp[ind1-1][ind2],dp[ind1][ind2-1]));
                }
            }
        }
        return dp[n1][n2];
    }
};