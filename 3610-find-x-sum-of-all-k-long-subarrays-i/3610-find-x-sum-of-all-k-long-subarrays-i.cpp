class Solution {
public:
    int find(unordered_map<int ,int>&mp, int x){
        vector<pair<int,int>>v;
        for(auto &[key,value]:mp){
            v.push_back({value, key});
        }
        sort(v.rbegin(),v.rend());
        int sum=0;
        for(int i=0;i<min((int)v.size(),x);i++) sum+=v[i].second*v[i].first;

        return sum;
    }
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>result;
        unordered_map<int,int>mp;
        for(int i=0;i<k;i++) mp[nums[i]]++;
        result.push_back(find(mp,x));
        for(int i=k;i<nums.size();i++){
            if(--mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
            mp[nums[i]]++;
            result.push_back(find(mp,x));
        }
        return result;
    }
};