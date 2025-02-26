class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int n=s.size();
        int countSubString=0;
        int a=0,b=0,c=0;
        for(int i=0,j=0;i<n;i++){
            if(s[i]=='a') a++;
            if(s[i]=='b') b++;
            if(s[i]=='c') c++;
            while(a>0&&b>0&&c>0){
                countSubString+=(n-i);
                if(s[j]=='a') a--;
                if(s[j]=='b') b--;
                if(s[j]=='c') c--;
                j++;
            }
        }
        return countSubString;
    }
};