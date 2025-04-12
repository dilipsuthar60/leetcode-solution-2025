class Solution {
public:
    long long countGoodIntegers(int n, int k) {
        unordered_set<string>st;
        int d=(n+1)/2;
        int start=pow(10,d-1);
        int end=pow(10,d)-1;
        for(int i=start;i<=end;i++){
            string left=to_string(i);
            string right="";
            string full="";
            if(n%2==0){
                right=left;
            }
            else{
                right=left.substr(0,d-1);
            }
            reverse(right.begin(),right.end());
            full=left+right;
            long long number=stoll(full);
            if(number%k==0){
                sort(full.begin(),full.end());
                st.insert(full);
            }
        }
        long long result=0;
        long long factorial[11]={0};
        factorial[0]=1;
        for(int i=1;i<11;i++){
            factorial[i]=i*factorial[i-1];
        }
        for(auto &s:st){
            int digitCount[11]={0};
            for(int i=0;i<s.size();i++){
                digitCount[s[i]-'0']++;
            }
            int totalDigit=n;
            int zeroDigit=digitCount[0];
            int nonZeroDigit=totalDigit-zeroDigit;
            long long current = nonZeroDigit*factorial[n-1];
            for(int i=0;i<11;i++){
                current/=factorial[digitCount[i]];
            }
            result+=current;
        }
        return result;
    }
};