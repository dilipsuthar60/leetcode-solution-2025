class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int zeroCount=count(nums.begin(),nums.end(),0);
        if(zeroCount==n) return 0;
        int totalXor=0;
        for(auto &element:nums) totalXor^=element;
        if(totalXor!=0) return n;
        return n-1;
    }
};