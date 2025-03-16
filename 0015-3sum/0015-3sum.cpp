class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n-1;i++)
        {
            if(i&&nums[i]==nums[i-1])
            {
                continue;
            }
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                if(l>i+1&&nums[l]==nums[l-1])
                {
                    l++;
                    continue;
                }
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==0)
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(sum>0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        return ans;
    }
};