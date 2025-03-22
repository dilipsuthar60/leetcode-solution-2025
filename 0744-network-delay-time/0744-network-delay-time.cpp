class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int,int>>dp[n+100];
        for(auto it:times)
        {
            dp[it[0]].push_back({it[1],it[2]});
        }
        vector<int>dis(n+1,INT_MAX);
        set<pair<int,int>>s;
        s.insert({0,k});
        dis[k]=0;
        while(s.size())
        {
            auto it=*s.begin();
            s.erase(s.begin());
            int wt=it.first;
            int node=it.second;
            for(auto it:dp[node])
            {
                int child=it.first;
                int new_wt=it.second;
                if(dis[child]>wt+new_wt)
                {
                    dis[child]=wt+new_wt;
                    s.insert({dis[child],child});
                }
            }
        }
        int ans=*max_element(dis.begin()+1,dis.end());
        if(ans==INT_MAX)
        {
            return -1;
        }
        return ans;
    }
};