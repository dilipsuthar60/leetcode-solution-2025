class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        vector<long long >suffixMaximum(n,0);
        suffixMaximum[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMaximum[i]=max(suffixMaximum[i+1],1ll*nums[i]);
        }
        long long prefixMaximum=nums[0];
        long long ans=0;
        for(int i=1;i<n-1;i++){
            ans=max(ans,(prefixMaximum-nums[i])*suffixMaximum[i+1]);
            prefixMaximum=max(prefixMaximum,1ll*nums[i]);
        }
        return ans;
    }
};