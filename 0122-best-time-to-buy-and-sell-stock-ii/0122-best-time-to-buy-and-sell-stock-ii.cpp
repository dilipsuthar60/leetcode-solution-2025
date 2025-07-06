class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cost=0;
        for(int i=1;i<prices.size();i++){
            cost+=max(0,prices[i]-prices[i-1]);
        }
        return cost;
    }
};