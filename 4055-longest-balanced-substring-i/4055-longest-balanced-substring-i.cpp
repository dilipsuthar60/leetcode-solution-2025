class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size();
        int ans=1;
        for(int i=0;i<n;i++){
            int dp[26]={0};
            for(int j=i;j<n;j++){
                dp[s[j]-'a']++;
                int first=-1;
                int isValid=true;
                for(int k=0;k<26;k++){
                    if(dp[k]){
                        if(first==-1){
                            first=dp[k];
                        }
                        else if(first!=dp[k]){
                            isValid=false;
                        }
                    }
                }
                if(isValid){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};