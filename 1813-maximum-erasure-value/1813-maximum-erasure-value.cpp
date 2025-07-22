class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int>s;
        int maxSum=0;
        for(int i=0,j=0,n=nums.size(),sum=0;i<n;i++){
            sum+=nums[i];
            while(s.find(nums[i])!=s.end()){
                sum-=nums[j];
                s.erase(nums[j++]);
            }
            maxSum=max(maxSum,sum);
            s.insert(nums[i]);
        }
        return maxSum;
    }
};