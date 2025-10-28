class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n=nums.size();
        int rightSum=accumulate(nums.begin(),nums.end(),0);
        int leftSum=0, count=0;
        for(int i=0;i<n;i++){
            leftSum+=nums[i];
            rightSum-=nums[i];
            if(nums[i]!=0){
                continue;
            }
            if(leftSum==rightSum) count+=2;

            if(abs(leftSum-rightSum)==1) count+=1;
        }
        return count;
    }
};