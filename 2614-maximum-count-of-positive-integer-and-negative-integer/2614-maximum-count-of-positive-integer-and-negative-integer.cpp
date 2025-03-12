class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int positive=0,negative=0;
        for(int i=0;i<nums.size();i++){
            positive+=(nums[i]>0);
            negative+=(nums[i]<0);
        }
        return max(positive, negative);
    }
};