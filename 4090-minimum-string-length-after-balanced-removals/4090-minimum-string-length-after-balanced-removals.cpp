class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            count+=(s[i]=='a')?1:-1;
        }
        return abs(count);
    }
};