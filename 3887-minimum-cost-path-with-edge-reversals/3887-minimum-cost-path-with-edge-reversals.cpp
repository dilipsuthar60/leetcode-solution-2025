class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>dp(n+1);
        for(auto &it:edges){
            dp[it[0]].push_back({it[1],it[2]});
            dp[it[1]].push_back({it[0],2*it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        vector<bool>visited(n+1,false);
        vector<int>dis(n+1, 1e8);
        dis[0]=0;
        while(pq.size()){
            auto [parentCost,parentNode]=pq.top();
            pq.pop();
            if(visited[parentNode]){
                continue;
            }
            visited[parentNode]=1;
            for(auto &[childNode, childCost]:dp[parentNode]){
                if(dis[childNode]>(childCost+parentCost)){
                    dis[childNode] = (childCost+parentCost);
                    pq.push({dis[childNode], childNode});
                }
            }
        }
        return (dis[n-1]==1e8)?-1:dis[n-1];
    }
};