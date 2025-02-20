class Solution {
public:
    int maxDistance(string s, int k) {
        int n=s.size();
        int dp[26]={0};
        int ans=0;
        for(int i=0;i<n;i++){
            dp[s[i]-'A']++;
            int current=min(i+1,2*k+abs(dp['N'-'A']-dp['S'-'A'])+abs(dp['E'-'A']-dp['W'-'A']));
            ans=max(ans,current);
        }
        return ans;
    }
};