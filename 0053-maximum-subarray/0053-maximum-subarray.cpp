class Solution {
public:
    int maxSubArray(vector<int>& nums)
    {
        int n=nums.size();
        int maximumSum=nums[0];
        int currentSum=nums[0];
        for(int i=1;i<n;i++){
            currentSum=max(currentSum+nums[i], nums[i]);
            maximumSum=max(maximumSum, currentSum);
        }
        return maximumSum;
    }
};