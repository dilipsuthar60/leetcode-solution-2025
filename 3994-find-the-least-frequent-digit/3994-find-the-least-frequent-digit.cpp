class Solution {
public:
    int getLeastFrequentDigit(int n) {
        int digitFreq[10];
        memset(digitFreq, 0, sizeof(digitFreq));
        string s=to_string(n);
        for(auto &it:s){
            digitFreq[it-'0']++;
        }
        int minFreq=1e8;
        int ans=1e8;
        for(int i=0;i<10;i++){
            if(!digitFreq[i]) continue;
            if(digitFreq[i]<minFreq){
                minFreq=digitFreq[i];
                ans=i;
            }
        }
        return ans;
    }
};