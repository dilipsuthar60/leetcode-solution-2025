class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int ans=-1;
        int minValue=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(minValue<nums[i]){
                ans=max(ans,nums[i]-minValue);
            }
            minValue=min(minValue,nums[i]);
        }
        return ans;
    }
};