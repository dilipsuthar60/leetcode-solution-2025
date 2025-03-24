class Solution 
{
public:
    int numOfMinutes(int n,int ID,vector<int>& manager,vector<int>&time) 
    {
        vector<int>dp[n+1];
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i]!=-1)
            {
                dp[manager[i]].push_back(i);
            }
        }
        queue<pair<int,int>>q;
        q.push({ID,0});
        int ans=0;
        while(q.size())
        {
            auto  temp=q.front();
            int parent=temp.first;
            int parent_time=temp.second;
            q.pop();
            ans=max(ans,parent_time);
            for(auto &it:dp[parent])
            {
                q.push({it,parent_time+time[parent]});
            }
        }
        return ans;
    }
};