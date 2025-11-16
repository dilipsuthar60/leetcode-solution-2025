class Solution {
public:
    const int mod=1e9+7;
    int numSub(string s) {
        int n=s.size();
        int one=0, result=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                one++;
            }
            else{
                one=0;
            }
            result+=one;
            result%=mod;
        }
        return result;
    }
};