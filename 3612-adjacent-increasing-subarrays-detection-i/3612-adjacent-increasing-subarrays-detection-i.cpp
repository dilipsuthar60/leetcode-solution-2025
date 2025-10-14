class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=1,inc=1,prevInc=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                inc++;
            }
            else{
                prevInc=inc;
                inc=1;
            }
            int currentIncreasingLength=max(inc/2, min(inc,prevInc));
            if(currentIncreasingLength>=k){
                return  true;
            }
        }
        return false;
    }
};