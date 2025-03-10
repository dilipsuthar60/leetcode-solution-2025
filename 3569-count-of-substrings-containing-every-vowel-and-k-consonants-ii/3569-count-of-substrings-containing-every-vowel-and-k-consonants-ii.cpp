class Solution {
public:
    long long find(string &s,int k){
        string vowel="aeiou";
        unordered_map<char,int>mp;
        int consonants=0;
        long long count=0;
        for(int i=0,j=0,n=s.size();i<n;i++){
            if(vowel.find(s[i])!=string::npos){
                mp[s[i]]++;
            }
            else{
                consonants++;
            }
            while(mp.size()==5&&consonants>k){
                if(vowel.find(s[j])!=string::npos){
                    if(--mp[s[j]]==0){
                        mp.erase(s[j]);
                    }
                }
                else{
                    consonants--;
                }
                j++;
            }
            count+=(i-j+1);
        }
        return count;
    }
    long long countOfSubstrings(string word, int k) {
        return find(word,k)-find(word,k-1);
    }
};