class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1=str1.size();
        int n2=str2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        for(int ind1=1;ind1<=n1;ind1++){
            for(int ind2=1;ind2<=n2;ind2++){
                if(str1[ind1-1]==str2[ind2-1]){
                    dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
                }
                else{
                    dp[ind1][ind2] = max(dp[ind1-1][ind2],dp[ind1][ind2-1]);
                }
            }
        }
        int ind1=n1,ind2=n2;
        string ans;
        while(ind1>0 && ind2>0){
            if(str1[ind1-1]==str2[ind2-1]){
                ans.push_back(str1[ind1-1]);
                ind1--;
                ind2--;
            }
            else if(dp[ind1][ind2]==dp[ind1-1][ind2]){
                ans.push_back(str1[ind1-1]);
                ind1--;
            }
            else{
                ans.push_back(str2[ind2-1]);
                ind2--;
            }
        }
        while(ind1>0){
            ans.push_back(str1[ind1-1]);
            ind1--;
        }
        while(ind2>0){
            ans.push_back(str2[ind2-1]);
            ind2--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};