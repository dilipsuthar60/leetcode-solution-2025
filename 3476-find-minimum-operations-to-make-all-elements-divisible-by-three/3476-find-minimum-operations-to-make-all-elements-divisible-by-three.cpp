class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cost=0;
        for(int i=0;i<nums.size();i++){
            int reminder=nums[i]%3;
            cost+=min(reminder, 3-reminder);
        }
        return cost;
    }
};