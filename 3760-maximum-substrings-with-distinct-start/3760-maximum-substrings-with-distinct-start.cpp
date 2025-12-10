class Solution {
public:
    int maxDistinct(string s) {
        return (unordered_set<char>{s.begin(),s.end()}).size();
    }
};