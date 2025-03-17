class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        int ans=0;
        long long prod=1;
        for(int i=0,j=0,n=nums.size();i<n;i++){
            prod*=nums[i];
            while(prod>=k){
                prod/=(1ll*nums[j++]);
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};