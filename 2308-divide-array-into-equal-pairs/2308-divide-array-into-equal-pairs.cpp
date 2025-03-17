class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto &num:nums) mp[num]++;
        for(auto &[key,value]:mp){
            if(value&1){
                return false;
            }
        }
        return true;
    }
};