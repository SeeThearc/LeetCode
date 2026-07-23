class Solution {
public:
    int find(int i,int j,int n1,int n2,vector<vector<int>>&dp,string &s,string &t){
        if(j==t.size())return 1;
        if(i==s.size())return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int pick = 0 ,notpick=0;
        if(s[i]==t[j]){
            pick = find(i+1,j+1,n1,n2,dp,s,t);
        }
        notpick = find(i+1,j,n1,n2,dp,s,t);
        return dp[i][j] = pick+notpick;
    }
    int numDistinct(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return find(0,0,n1,n2,dp,s,t);
    }
};