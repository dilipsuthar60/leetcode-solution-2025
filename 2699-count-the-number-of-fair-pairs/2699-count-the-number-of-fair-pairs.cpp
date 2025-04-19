class Solution {
public:
    long long countPairLessThanK(vector<int>& nums, int k) {
        long long count = 0;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] <= k) {
                count += (r - l);
                l++;
            } else {
                r--;
            }
        }
        return count;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        return countPairLessThanK(nums, upper) -
               countPairLessThanK(nums, lower - 1);
    }
};