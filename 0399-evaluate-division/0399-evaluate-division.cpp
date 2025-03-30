class Solution {
public:
    double find(unordered_map<string,vector<pair<string,double>>>&dp,vector<string>&question)
    {
        string start=question[0];
        string end=question[1];
        if(dp.find(start)==dp.end())
        {
            return -1.0000;
        }
        queue<pair<string,double>>q;
        q.push({start,1.0});
        unordered_set<string>vis;
        vis.insert(start);
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            string node=temp.first;
            double wet=temp.second;
            if(node==end)
            {
                return wet;
            }
            for(auto it:dp[node])
            {
                if(vis.count(it.first)==0)
                {
                    q.push({it.first,it.second*wet});
                    vis.insert(it.first);
                }
            }
        }
        return -1.00;
    }
    vector<double> calcEquation(vector<vector<string>>& edu, vector<double>& val,vector<vector<string>>& q)
    {
        unordered_map<string,vector<pair<string,double>>>mp;
        for(int i=0;i<edu.size();i++)
        {
            string u=edu[i][0];
            string v=edu[i][1];
            double wt=val[i];
            mp[u].push_back({v,wt});
            mp[v].push_back({u,1/wt});
        }
        vector<double>ans;
        for(auto it:q)
        {
            ans.push_back(find(mp,it));
        }
        return ans;
    }
};