class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;
        int maxElementFreq=0;
        for(auto &element: nums) {
            maxElementFreq=max(maxElementFreq, ++mp[element]);
        }
        int count=0;
        for(auto &[key, value]:mp){
            count+=((value==maxElementFreq)?value:0);
        }
        return count;
    }
};