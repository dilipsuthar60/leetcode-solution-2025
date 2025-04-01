class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long>dp(n+1,0);
        dp[n-1]=questions.back()[0];
        for(int i=n-2;i>=0;i--){
            dp[i]=dp[i+1];
            if(i+questions[i][1]+1<n){
                dp[i]=max(dp[i],questions[i][0]+dp[i+questions[i][1]+1]);
            }
            else{
                dp[i]=max(dp[i],1ll*questions[i][0]);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};