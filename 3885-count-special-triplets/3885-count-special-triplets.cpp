class Solution {
public:
    const int mod=1e9+7;
    int specialTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,long long>mp;
        vector<long long>left(n,0),right(n,0);
        for(int i=0;i<n;i++){
            if(mp.find(2*nums[i])!=mp.end()){
                left[i] = mp[2*nums[i]]; 
            }
            mp[nums[i]]++;
        }
        mp.clear();
        for(int i=n-1;i>=0;i--){
            if(mp.find(2*nums[i])!=mp.end()){
                right[i] = mp[2*nums[i]]; 
            }
            mp[nums[i]]++;
        }
        long long count=0;
        for(int i=1;i<n-1;i++){
            count+=left[i]*right[i];
            count%=mod;
        }
        return count;
    }
};