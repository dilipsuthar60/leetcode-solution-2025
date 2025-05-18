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
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int sum=digitSum(nums[i]);
            if(i==sum){
                return sum;
            }
        }
        return -1;
    }
};