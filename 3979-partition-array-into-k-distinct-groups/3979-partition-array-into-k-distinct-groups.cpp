class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k) return false;
        unordered_map<int,int>mp;
        for(auto &element:nums) mp[element]++;
        int groupSize=n/k;
        for(auto &[key, value]:mp){
            if(value>groupSize) return false;
        }
        return true;
    }
};