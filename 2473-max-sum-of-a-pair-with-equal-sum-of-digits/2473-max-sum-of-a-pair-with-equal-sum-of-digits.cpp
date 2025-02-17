class Solution {
public:
    int maximumSum(vector<int>& nums) 
    {
        int count=-1;
        unordered_map<int,int>mp,vis;
        auto digit=[&](int n)
        {
            int sum=0;
            while(n)
            {
                sum+=n%10; 
                n/=10;
            }
            return sum;
        };
        for(auto it:nums)
        {
            int val=digit(it);
            if(mp.find(val)!=mp.end())
            {
                count=max(it+vis[val],count);
            }
            mp[val]++;
            vis[val]=max(vis[val],it);
        }
        return count;
    }
};