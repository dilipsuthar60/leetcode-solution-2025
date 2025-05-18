class Solution {
public:
    int digitSum(int number){
        int totalDigitSum=0;
        while(number){
            totalDigitSum+=number%10;
            number/=10;
        }
        return totalDigitSum;
    }
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>sorted;
        for(int i=0;i<n;i++){
            sorted.push_back({digitSum(nums[i]), nums[i], i});
        }
        sort(sorted.begin(),sorted.end());
        for(int i=0;i<n;i++){
            nums[i]=sorted[i][2];
        }
        int minimumSwapCount=0;
        for(int i=0;i<n;i++){
            while(nums[i]!=nums[nums[i]]){
                minimumSwapCount++;
                swap(nums[i],nums[nums[i]]);
            }
        }
        return minimumSwapCount;
    }
};