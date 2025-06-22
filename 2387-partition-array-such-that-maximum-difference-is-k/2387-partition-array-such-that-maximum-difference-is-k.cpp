class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int mi=nums[0];
        int mx=nums[0];
        int n=nums.size();
        int count=1;
        for(int i=0;i<n;i++){
            mi=min(mi,nums[i]);
            mx=max(mx,nums[i]);
            if(mx-mi>k){
                count++;
                mi=nums[i];
                mx=nums[i];
            }
        }
        return count;
    }

};