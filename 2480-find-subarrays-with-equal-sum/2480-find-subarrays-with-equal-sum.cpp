class Solution {
public:
    bool findSubarrays(vector<int>& nums) 
    {
        int n=nums.size();
        unordered_set<int>s;
        for(int i=0;i<n-1;i++){
            if(s.find(nums[i]+nums[i+1])!=s.end()) return true;
            s.insert(nums[i]+nums[i+1]);
        }
        return false;
    }
};