class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0,prev=nums[0];i<n;i++){
            prev=max(prev,nums[i]);
            ans+=(prev==nums[i]);
        }
        return ans;
    }
};