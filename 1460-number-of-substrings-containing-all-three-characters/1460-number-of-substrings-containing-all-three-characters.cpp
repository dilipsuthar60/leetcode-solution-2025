class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int size=s.size();
        int last[5];
        memset(last,-1,sizeof(last));
        int j=0;
        for(int i=0;i<size;i++){
            last[s[i]-'a']=i;
            ans+=1+min({last[0],last[1],last[2]});
        }
        return ans;
    }
};