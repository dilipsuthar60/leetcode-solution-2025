class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans=1e8;
        for(int i=0, n=nums.size(),sum=0, j=0;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                ans=min(ans, i-j+1);
                sum-=nums[j++];
            }
        }
        return ans==1e8?0:ans;
    }
};