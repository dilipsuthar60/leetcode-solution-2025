class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        int rem=totalSum%k;
        return rem;
    }
};