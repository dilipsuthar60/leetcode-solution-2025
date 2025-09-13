class Solution {
public:
    int maxFreqSum(string s) {
        vector<int>freq(26, 0);
        for(auto &ch:s) freq[ch-'a']++;
        string vowel="aeiou";
        int maxFreqOfVowel=0, maxFreqOfConsonant=0;
        for(int i=0;i<26;i++){
            if(vowel.find(char(i+'a'))!=string::npos){
                maxFreqOfVowel=max(maxFreqOfVowel, freq[i]);
            }
            else{
                maxFreqOfConsonant=max(maxFreqOfConsonant, freq[i]);
            }
        }
        return maxFreqOfVowel+maxFreqOfConsonant;
    }
};