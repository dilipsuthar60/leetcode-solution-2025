class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>isValidPrefix(n),isValidSuffix(n);
        vector<long long>prefix(n),suffix(n);
        
        isValidPrefix[0]=1;
        prefix[0]=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                prefix[i]+=(prefix[i-1]+nums[i]);
                isValidPrefix[i]=isValidPrefix[i]||(isValidPrefix[i-1]);
            }
        }

        isValidSuffix[n-1]=1;
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1]){
                suffix[i]+=(suffix[i+1]+nums[i]);
                isValidSuffix[i]=isValidSuffix[i]||isValidSuffix[i+1];
            }
        }
        long long ans=1e18;
        for(int i=0;i<n-1;i++){
            if(isValidPrefix[i]&&isValidSuffix[i+1]){
                ans=min(ans,llabs(prefix[i]-suffix[i+1]));
            }
        }
        return ans==1e18?-1:ans;
    }
};