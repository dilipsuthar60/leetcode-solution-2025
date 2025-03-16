class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<int>left(26,-1),right(26,-1);
        for(int i=0;i<s.size();i++){
            int charIndex=s[i]-'a';
            if(left[charIndex]==-1){
                left[charIndex]=i;
            }
            right[charIndex]=i;
        }
        int palindromCount=0;
        for(int i=0;i<26;i++){
            int leftMostIndex=left[i];
            int rightMostIndex=right[i];
            if(leftMostIndex==-1||rightMostIndex==-1) continue;
            unordered_set<char>visited;
            for(int j=leftMostIndex+1;j<rightMostIndex;j++){
                if(visited.find(s[j])==visited.end()){
                    visited.insert(s[j]);
                }
            }
            palindromCount+=visited.size();
        }
        return palindromCount;
    }
};