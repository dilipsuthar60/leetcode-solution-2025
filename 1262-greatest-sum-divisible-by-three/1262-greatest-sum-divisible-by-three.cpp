class Solution {
public:
    int dp[40005][4];
    int find(vector<int>&nums, int index, int rem){
        if(index>=nums.size()){
            return rem==0?0:INT_MIN;
        }
        if(dp[index][rem]!=-1){
            return dp[index][rem];
        }
        int take=nums[index]+find(nums,index+1, (rem+nums[index])%3);
        int notTake=find(nums,index+1,rem);
        return dp[index][rem]= max(take, notTake);
    }
    int maxSumDivThree(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return find(nums,0,0);
    }
};