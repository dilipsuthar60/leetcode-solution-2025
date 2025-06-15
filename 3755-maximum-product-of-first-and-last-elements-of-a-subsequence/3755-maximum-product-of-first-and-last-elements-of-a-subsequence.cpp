class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int n=nums.size();
        long long ans=1ll*nums[0]*nums[m-1];
        long long mx=nums[0], mi=nums[0];
        for(int i=m-1;i<n;i++){
            mx=max(mx, 1ll*nums[i-m+1]);
            mi=min(mi, 1ll*nums[i-m+1]);
            ans=max({ans, mx*nums[i], mi*nums[i]});
        }
        return ans;
    }
};