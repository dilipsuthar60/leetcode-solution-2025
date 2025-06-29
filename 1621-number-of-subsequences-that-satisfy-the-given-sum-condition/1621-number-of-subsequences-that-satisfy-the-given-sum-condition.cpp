class Solution {
public:
    const int mod=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1,1);
        for(int i=1;i<=n;i++){
            dp[i]=(2*dp[i-1])%mod;
        }
        int l=0, r=n-1;
        long long ans=0;
        while(l<=r){
            if(nums[l]+nums[r]<=target){
                ans+=dp[r-l];
                ans%=mod;
                l++;
            }
            else{
                r--;
            }
        }
        return ans%mod;
    }
};