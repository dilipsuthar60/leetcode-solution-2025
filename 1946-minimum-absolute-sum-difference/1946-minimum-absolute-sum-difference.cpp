class Solution {
public:
    const int mod=1e9+7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) 
    { 
        using ll=long long;
        int n=nums1.size();
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=abs(nums1[i]-nums2[i]);
            sum%=mod;
        }
        ll ans=1e18;
        vector<int>nums=nums1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            auto index=lower_bound(nums.begin(),nums.end(),nums2[i])-nums.begin();
            ll diff=abs(nums1[i]-nums2[i]);
            if(index<nums1.size())
            {
                ans=min(ans,-diff+abs(nums[index]-nums2[i]));
            }
            if(index)
            {
                ans=min(ans,-diff+abs(nums[index-1]-nums2[i]));
            }
        }
        return (1ll*sum+1ll*ans+mod)%mod;
    }
};