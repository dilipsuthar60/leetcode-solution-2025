class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) 
    {
        int maximumOr=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(auto &element:nums){
            maximumOr|=element;
            unordered_map<int,int>current=mp;
            for(auto &[key,value]:current){
                mp[key|element]+=value;
            }
        }
        return mp[maximumOr];
    }
};