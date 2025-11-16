class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int n=nums.size();
        int ans=0;
        int curr=0;
        for(int i=0;i<n;i++){
            curr=(nums[i]==1)?curr+1:0;
            ans=max(ans,curr);
        }
        return ans;
    }
};