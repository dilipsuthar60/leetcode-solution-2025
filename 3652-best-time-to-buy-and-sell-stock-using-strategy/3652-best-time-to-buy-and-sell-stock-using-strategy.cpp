class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        vector<long long>prefix(n+1,0),profit(n+1,0);
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+prices[i];
            profit[i+1]=profit[i]+prices[i]*strategy[i];
        }
        long long ans=profit.back();
        for(int i=k-1;i<n;i++){
            long long leftProfit=profit[i-k+1];
            long long rightProfit = profit.back()-profit[i+1];

            long long midPart=prefix[i+1]-prefix[i-(k/2)+1];
            ans=max(ans, leftProfit+midPart+rightProfit);
        }
        return ans;
    }
};