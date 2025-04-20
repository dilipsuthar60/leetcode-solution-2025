class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int ans=0;
        unordered_map<int,int>mp;
        for(auto &it:answers) mp[it]++;
        for(auto &[key,freq]:mp){
            ans+=((freq+key)/(key+1))*(key+1);
        }
        return ans;
    }
};