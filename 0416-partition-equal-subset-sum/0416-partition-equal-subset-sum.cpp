class Solution {
public:
    vector<vector<int>>dp;
    bool find(vector<int>&nums,int index, int sum){
        if(index>=nums.size()||sum<0){
            return sum==0;
        }
        if(dp[index][sum]!=-1) return dp[index][sum];
        return dp[index][sum]=find(nums,index+1,sum)||find(nums,index+1,sum-nums[index]);
    }
    bool canPartition(vector<int>& nums) {
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        if(totalSum&1) return 0;
        dp=vector<vector<int>>(nums.size()+1,vector<int>(totalSum/2+1,-1));
        return find(nums,0,totalSum/2);
    }
};