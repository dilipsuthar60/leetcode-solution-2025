class Solution {
public:
    void dfs(const vector<vector<int>>&dp, int node, vector<bool>&vis){
        vis[node]=1;
        for(auto &it:dp[node]){
            if(!vis[it]){
                dfs(dp, it, vis);
            }
        }
    }
    int find(const vector<vector<int>>&edges, int n, int time){
        vector<vector<int>>dp(n+1);
        for(auto &it:edges){
            if(it[2]>time){
                dp[it[0]].push_back(it[1]);
                dp[it[1]].push_back(it[0]);
            }
        }
        int countComponent=0;
        vector<bool>vis(n+1);
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            countComponent++;
            dfs(dp, i, vis);
        }
        return countComponent;
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        int l=0, r=1e9+1;
        int ans=r;
        while(l<=r){
            int mid=(l+r)/2;
            int count=find(edges, n, mid);
            if(count>=k){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};