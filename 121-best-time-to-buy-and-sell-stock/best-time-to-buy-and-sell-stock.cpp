class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxprofit=0;
        int minpri=INT_MAX;
        for(int price:prices){
            minpri=min(minpri,price);
            maxprofit=max(maxprofit,price-minpri);
        }
        return maxprofit;
    }
};