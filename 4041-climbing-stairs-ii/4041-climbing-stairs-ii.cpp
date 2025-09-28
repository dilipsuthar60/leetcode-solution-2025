class Solution {
public:
    vector<int>dp;
    int getCost(int a, int b){
        int value=abs(a-b);
        return value*value;
    }
    int find(vector<int>&nums, int index, int n){
        if(index>=n) return 0;
        int ans=1e9;
        if(dp[index]!=-1) return dp[index];
        if(index<n){
            ans=min(ans, getCost(index,index+1)+nums[index]+find(nums,index+1, n));
        }
        if(index+1<n){
            ans=min(ans, getCost(index,index+2)+nums[index+1]+find(nums,index+2, n));
        }
        if(index+2<n){
            ans=min(ans, getCost(index,index+3)+nums[index+2]+find(nums,index+3, n));
        }
        return dp[index]= ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        dp=vector<int>(n+2,-1);
        return find(costs, 0, n);
    }
};