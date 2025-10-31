class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        for(int i=0, lastMinimumProfit=1e8;i<prices.size();i++){
            lastMinimumProfit=min(lastMinimumProfit,prices[i]);
            profit=max(profit, prices[i]-lastMinimumProfit);
        }
        return profit;
    }
};