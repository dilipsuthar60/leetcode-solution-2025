class Solution {
public:
    int getPrefixLength(string &word1, string &word2){
        int counter=0;
        for(int i=0;i<min(word1.size(),word2.size());i++){
            if(word1[i]!=word2[i]) break;
            counter++;
        }
        return counter;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n=words.size();
        vector<int>ans(n,0);
        vector<int>prefix(n+10,0),suffix(n+10,0);
        // calculating all prefix for maximum......
        for(int i=1;i<n;i++){
            prefix[i]=getPrefixLength(words[i],words[i-1]);
            prefix[i]=max(prefix[i],prefix[i-1]);
        }
        // calculating all suffix for maximum......
        for(int i=n-2;i>=0;i--){
            suffix[i]=getPrefixLength(words[i],words[i+1]);
            suffix[i]=max(suffix[i],suffix[i+1]);
        }
        for(int i=0;i<n;i++){
            if(i==0){
                ans[i]=suffix[i+1];
            }
            else if(i==n-1){
                ans[i]=prefix[i-1];
            }
            else{
                ans[i]=max(prefix[i-1],suffix[i+1]);
                ans[i]=max(ans[i], getPrefixLength(words[i-1],words[i+1]));
            }
        }
        return ans;
    }
};