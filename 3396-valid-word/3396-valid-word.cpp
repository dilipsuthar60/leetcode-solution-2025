class Solution {
public:
    bool isDigit(char ch){
        return ch>='0'&&ch<='9';
    }

    bool isAlpha(char ch){
        return (ch>='a'&&ch<='z')|| (ch>='A'&&ch<='Z');
    }

    bool isValid(string s) {
        int n=s.size();
        if(n<3) return false;
        bool vowel=false, consonant=false;
        string st="aeiouAEIOU";
        for(int i=0;i<n;i++){
            if(isAlpha(s[i])|| isDigit(s[i])){
                if(st.find(s[i])!=string::npos){
                    vowel=true;
                }
                else if(isAlpha(s[i])){
                    consonant=true;
                }
            }
            else{
                return false;
            }
        }
        return consonant&&vowel;
    }
};