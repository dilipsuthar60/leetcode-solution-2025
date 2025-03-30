class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int>ans;
        long long currentSum=0;
        for(int i=0;i<word.size();i++){
            currentSum=(currentSum*10+word[i]-'0')%m;
            ans.push_back((currentSum==0)?1:0);
        }
        return ans;
    }
};