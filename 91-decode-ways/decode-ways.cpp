class Solution {
public:
    int find(int i,string s,vector<int>&dp,int n){
        if(i>=n)return 1;
        if(dp[i]!=-1)return dp[i];
        int goone=0,gotwo=0;
        if(s[i]=='0'){
            return 0;
        }
        else{
            goone = find(i+1,s,dp,n);
        }
        if(i<n-1 && ((s[i]=='2' && s[i+1]<'7') || (s[i]=='1'))){
            gotwo = find(i+2,s,dp,n);
        }
        return dp[i] = goone+gotwo;
    }
    int numDecodings(string s) {
        vector<int>dp(s.size(),-1);
        int n = s.size();
        return find(0,s,dp,n);
    }
};