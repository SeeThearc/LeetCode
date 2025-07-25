class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int mini=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            int pro = prices[i]-mini;
            profit=max(profit,pro);
            if(prices[i]<mini){
                mini=prices[i];
            }
        }
        return profit;
    }
};