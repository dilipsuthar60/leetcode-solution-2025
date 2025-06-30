class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto& num : nums)
            mp[num]++;
        int ans = 0;
        for (auto& [key, value] : mp) {
            if (mp.find(key - 1) != mp.end()) {
                ans = max(ans, value + mp[key - 1]);
            }
        }
        return ans;
    }
};