class Solution {
public:
    const int mod=1e9+7;
    int numSub(string s) {
        int n=s.size();
        int one=0, result=0;
        for(int i=0;i<n;i++){
            one=(s[i]=='1')?one+1:0;
            result=(result+one)%mod;
        }
        return result;
    }
};