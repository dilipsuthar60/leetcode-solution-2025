class Solution {
public:

    int countMaxOrSubsets(vector<int>& nums) 
    {
        int n=nums.size();
        int max_or=0;
        unordered_map<int,int>mp;
        for(int i=1;i<(1<<n);i++)
        {
            int ans=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    ans|=nums[j];
                }
            }
            mp[ans]++;
            max_or=max(max_or,ans);
        }
        return mp[max_or];
    }
};