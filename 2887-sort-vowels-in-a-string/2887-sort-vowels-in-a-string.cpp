class Solution {
public:
    bool isVowel(char ch){
        string s="aeiouAEIOU";
        return s.find(ch)!=string::npos;
    }
    string sortVowels(string s) {
        string vowel="";
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])) vowel+=s[i];
        }
        sort(vowel.begin(),vowel.end());
        for(int i=0,index=0;i<s.size();i++){
            if(isVowel(s[i])){
                s[i]=vowel[index++];
            }
        }
        return s;
    }
};