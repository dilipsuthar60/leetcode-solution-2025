class Solution {
public:
    bool find(vector<int>&nums,vector<vector<int>>&queries,int mid){
        int n=nums.size();
        vector<int>rangeSum(n+10,0);
        for(int i=0;i<mid;i++){
            rangeSum[queries[i][0]]+=queries[i][2];
            rangeSum[queries[i][1]+1]-=queries[i][2];
        }
        for(int i=1;i<n;i++){
            rangeSum[i]+=rangeSum[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>rangeSum[i]) return false;
        }
        return true;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int l=0;
        int r=queries.size();
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(find(nums,queries, mid)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};