class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_map<int, int> mp;
        for (auto& element : nums)
            mp[element]++;

        for (auto& [key, value] : mp) {
            if (value == 2) {
                result.push_back(key);
            }
        }

        return result;
    }
};