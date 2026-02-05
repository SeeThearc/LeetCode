class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int>maxarr;
        int n = prices.size();
        int maxi=INT_MIN;
        for(int i=prices.size()-1;i>=0;i--){
            maxi = max(prices[i],maxi);
            maxarr.push_back(maxi);
        }
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans = max(ans,maxarr[n-i-1]-prices[i]);
        }
        return ans;
    }
};