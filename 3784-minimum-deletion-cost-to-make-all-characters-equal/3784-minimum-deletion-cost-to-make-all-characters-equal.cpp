class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        int n=s.size();
        vector<long long>costSum(26,0);
        long long totalCost=0, ans=0;
        for(int i=0;i<n;i++){
            costSum[s[i]-'a']+=cost[i];
            totalCost+=cost[i];
        }
        for(int i=0;i<26;i++){
            ans=max(ans,costSum[i]);
        }
        return totalCost-ans;
    }
};