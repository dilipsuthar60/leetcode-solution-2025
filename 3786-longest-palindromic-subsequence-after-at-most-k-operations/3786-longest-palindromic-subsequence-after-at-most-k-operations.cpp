class Solution {
public:
    int dp[201][201][201];
    int find(string &s,int i,int j,int k){
        if(i>=j){
            return i==j;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        int ans=0;
        if(s[i]==s[j]){
            ans=max(ans,2+find(s,i+1,j-1,k));
        }
        ans=max({ans,find(s,i,j-1,k), find(s,i+1,j,k)});
        int current = min(abs(s[i]-s[j]),26-abs(s[i]-s[j]));
        if(current<=k){
            ans=max(ans,2+find(s,i+1,j-1,k-current));
        }
        return dp[i][j][k]= ans;
    }
    int longestPalindromicSubsequence(string s, int k){
        memset(dp,-1,sizeof(dp));
        return find(s,0,s.size()-1,k);
    }
};