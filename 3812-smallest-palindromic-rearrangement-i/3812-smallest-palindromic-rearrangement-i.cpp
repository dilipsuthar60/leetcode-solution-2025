class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        vector<int>dp(26,0);
        for(auto &ch:s) dp[ch-'a']++;
        int index=0;
        string ans = string(n,'#');
        char mid='#';
        for(int i=0;i<26;i++){
            while(dp[i]>=2){
                ans[index]=char('a'+i);
                ans[n-index-1]=char('a'+i);
                index++;
                dp[i]-=2;
            }
        }
        for(int i=0;i<26;i++){
            if(dp[i]){
                ans[index]=char('a'+i);
                break;
            }
        }
        return ans;
    }
};