class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+5,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=max(dp[i+1],questions[i][0]+dp[min(n+1,i+questions[i][1]+1)]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};