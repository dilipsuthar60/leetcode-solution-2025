class Solution {
public:
    int dp[255][255];
    int find(vector<int>&nums,int index,int k){
        if(index>=nums.size()||k<0){
            return (k==0)?0:INT_MAX;
        }
        if(dp[index][k]!=-1){
            return dp[index][k];
        }
        int currentXor=0;
        int ans=INT_MAX;
        for(int i=index;i<nums.size();i++){
            currentXor^=nums[i];
            ans=min(ans, max(currentXor, find(nums,i+1,k-1)));
        }
        return dp[index][k]= ans;
    }
    int minXor(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return find(nums,0,k);
    }
};