class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size(), count=0;
        sort(nums.begin(),nums.end());
        for(auto &it:nums){
            int index=upper_bound(nums.begin(),nums.end(),it)-nums.begin();
            int greaterElement=(n-index);
            if(greaterElement>=k){
                count++;
            }
        }
        return count;
    }
};