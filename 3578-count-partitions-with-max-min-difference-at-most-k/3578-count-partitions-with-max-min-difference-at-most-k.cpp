class Solution {
public:
    const int mod=1e9+7;
    int countPartitions(vector<int>& nums, int k) {
        int n=nums.size(), result=0;
        vector<int>dp(n+1,1);
        multiset<int>s;
        for(int i=0,j=0, sum=0;i<n;i++){
            s.insert(nums[i]);
            sum=(sum+dp[i])%mod;
            while(*s.rbegin()-*s.begin()>k){
                sum=(sum-dp[j]+mod)%mod;
                s.erase(s.find(nums[j++]));
            }
            dp[i+1]=sum%mod;
        }
        return dp.back();
    }
};