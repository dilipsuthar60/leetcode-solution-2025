class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        if(n<3) return false;
        bool vowel=false, consonant=false;
        string st="aeiouAEIOU";
        for(int i=0;i<n;i++){
            if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')||(s[i]>='0'&&s[i]<='9')){
                if(st.find(s[i])!=string::npos){
                    vowel=true;
                }
                else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
                    consonant=true;
                }
            }
            else{
                return false;
            }
        }
        cout<<"iir";
        return consonant&&vowel;
    }
};