class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int currentSum1=0,currentSum2=0;
        int maximumPositiveSum=0,maximumNegativeSum=0;
        for(int i=0;i<n;i++){
            currentSum1=max(currentSum1+nums[i],nums[i]);
            currentSum2=min(currentSum2+nums[i],nums[i]);

            maximumPositiveSum=max(maximumPositiveSum,currentSum1);
            maximumNegativeSum=min(maximumNegativeSum,currentSum2);
        }
        return max(abs(maximumNegativeSum),maximumPositiveSum);
    }
};