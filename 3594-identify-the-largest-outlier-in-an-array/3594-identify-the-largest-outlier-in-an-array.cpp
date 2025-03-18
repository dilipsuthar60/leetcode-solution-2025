class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int n=nums.size();
        int totalSum=accumulate(nums.begin(),nums.end(),0);
        multiset<int>s;
        for(auto &num:nums) s.insert(num);
        int ans=-1e9;
        for(int i=0;i<n;i++){
            s.erase(s.find(nums[i]));
            totalSum-=nums[i];
            if(totalSum%2==0&&(s.find(totalSum/2)!=s.end())){
                ans=max(ans,nums[i]);
            }
            s.insert(nums[i]);
            totalSum+=nums[i];
        }
        return ans;
    }
};