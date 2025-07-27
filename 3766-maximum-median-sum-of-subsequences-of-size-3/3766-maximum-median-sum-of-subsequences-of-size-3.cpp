class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int d=n/3;
        long long cost=0;
        for(int i=n-2;i>=d;i-=2){
            cost+=nums[i];
        }
        return cost;
    }
};