class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long ans=0;
        for(long long i=0,j=0,sum=0,n=nums.size();i<n;i++){
            sum+=nums[i];
            while(sum*(i-j+1)>=k){
                sum-=nums[j++];
            }
            ans+=(i-j+1);
        }
        return ans;
    }
};