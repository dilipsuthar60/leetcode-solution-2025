class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int index = 0;
        int n = nums.size();
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                    if (dp[i] > dp[index]) {
                        index = i;
                    }
                }
            }
        }
        vector<int> ans;
        while (index >= 0) {
            ans.push_back(nums[index]);
            index = parent[index];
        }
        return ans;
    }
};