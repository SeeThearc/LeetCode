class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int mod = 1e9;
        vector<vector<unsigned long long>>dp(n,vector<unsigned long long>(amount+1,0));
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=1;
            }
        }
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=amount;tar++){
                long long notTaken = dp[ind-1][tar];
                long long taken = 0;
                if(coins[ind]<=tar){
                    taken = dp[ind][tar-coins[ind]];
                }
                dp[ind][tar] = (unsigned long long)notTaken + taken; 
            }
        }
        return (int)dp[n-1][amount];
    }
};