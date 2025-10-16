class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int>mp;
        for(auto &it:nums){
            mp[(it%value+value)%value]++;
        }
        int counter=0;
        while(mp[counter%value]-->0){
            counter++;
        }
        return counter;
    }
};