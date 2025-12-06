class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int rightSum=accumulate(nums.begin(),nums.end(),0);
        int leftSum=0, count=0;
        for(int i=0;i<nums.size()-1;i++){
            leftSum+=nums[i];
            rightSum-=nums[i];
            count+=(abs(leftSum-rightSum)%2==0);
        }
        return count;
    }
};