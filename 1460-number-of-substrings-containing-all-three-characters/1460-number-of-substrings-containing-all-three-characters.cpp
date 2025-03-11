class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans=0;
        int size=s.size();
        int a=0,b=0,c=0;
        int j=0;
        for(int i=0;i<size;i++){
            if(s[i]=='a') a++;
            if(s[i]=='b') b++;
            if(s[i]=='c') c++;
            while(a>0&&b>0&&c>0){
                ans+=size-i;
                if(s[j]=='a') a--;
                if(s[j]=='b') b--;
                if(s[j]=='c') c--;
                j++;
            }
        }
        return ans;
    }
};