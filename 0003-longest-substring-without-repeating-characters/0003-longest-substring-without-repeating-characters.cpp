class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int dp[256];
        memset(dp,-1,sizeof(dp));
        int n=s.size();
        int i=0,j=0;
        int ans=0;
        while(i<n){
            if(dp[s[i]]==-1){
                dp[s[i]]=1;
                ans=max(ans,i-j+1);
                i++;
            }
            else{
                dp[s[j]]=-1;
                j++;
            }
        }
        return ans;
    }
};