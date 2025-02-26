class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int dp[n+1][2];
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            dp[i+1][0]=min(dp[i][0]+nums[i],nums[i]);
            dp[i+1][1]=max(dp[i][1]+nums[i],nums[i]);
            ans=max({ans,abs(dp[i+1][0]),abs(dp[i+1][1])});
        }
        return ans;
    }
};