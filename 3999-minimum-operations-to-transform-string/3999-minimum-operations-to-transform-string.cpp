class Solution {
public:
    int minOperations(string s) {
        int n=s.size();
        vector<int>dp(26,0);
        for(auto &it:s) dp[it-'a']++;
        int maxdistance=0;
        for(int i=1;i<26;i++){
            if(!dp[i]) continue;
            maxdistance=max(maxdistance, abs(26-i));
        }
        return maxdistance;
    }
};