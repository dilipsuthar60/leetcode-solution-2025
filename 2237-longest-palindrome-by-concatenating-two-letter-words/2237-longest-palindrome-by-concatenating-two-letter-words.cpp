class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int n=words.size();
        int dp[26][26];
        memset(dp,0,sizeof(dp));
        int len=0;
        for(int i=0;i<n;i++){
            int firstCharacter=words[i][0]-'a';
            int secondCharacter=words[i][1]-'a';
            if(dp[secondCharacter][firstCharacter]){
                len+=4;
                dp[secondCharacter][firstCharacter]--;
            }
            else{
                dp[firstCharacter][secondCharacter]++;
            }
        }
        for(int i=0;i<26;i++){
            if(dp[i][i]){
                len+=2;
                break;
            }
        }
        return len;
    }
};