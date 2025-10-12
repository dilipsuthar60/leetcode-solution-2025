class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=1;
        for(int i=0;i<n;i++){
            int dp[26]={0};
            int maxFreq=0, uniqueCharCount=0;
            for(int j=i;j<n;j++){
                maxFreq=max(maxFreq, ++dp[s[j]-'a']);
                if(dp[s[j]-'a']==1) uniqueCharCount++;
                if(maxFreq*uniqueCharCount==(j-i+1)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};