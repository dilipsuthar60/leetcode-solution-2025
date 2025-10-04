class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i=0,j=nums.size()-1;
        int maximumAreaWater=0;
        while(i<j){
            int currentArea=(j-i)*min(nums[i],nums[j]);
            maximumAreaWater=max(maximumAreaWater,currentArea);
            if(nums[i]<nums[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maximumAreaWater;
    }
};