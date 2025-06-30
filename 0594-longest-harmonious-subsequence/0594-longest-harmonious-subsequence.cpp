class Solution {
public:
    int findLHS(vector<int>& nums) {
        // solution - 1
        // int n = nums.size();
        // unordered_map<int, int> mp;
        // for (auto& num : nums)
        //     mp[num]++;
        // int ans = 0;
        // for (auto& [key, value] : mp) {
        //     if (mp.find(key + 1) != mp.end()) {
        //         ans = max(ans, value + mp[key +1]);
        //     }
        // }
        // return ans;




        // solution - 2

        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=0,ans=0;
        while(r<n){
            while(nums[r]-nums[l]>1){
                l++;
            }
            if(nums[r]-nums[l]==1){
                ans=max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};