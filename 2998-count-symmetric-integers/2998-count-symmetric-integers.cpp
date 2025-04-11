class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count=0;
        for(int i=low;i<=high;i++){
            string s=to_string(i);
            int n=s.size();
            if(n%2) continue;
            int leftPartSum=0, rightPartSum=0;
            for(int j=0;j<n/2;j++) leftPartSum+=(s[j]-'0');
            for(int j=n/2;j<n;j++) rightPartSum+=(s[j]-'0');
            count+=(leftPartSum==rightPartSum);
        }
        return count;
    }
};