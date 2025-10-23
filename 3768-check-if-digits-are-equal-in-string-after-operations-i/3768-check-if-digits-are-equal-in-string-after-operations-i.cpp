class Solution {
public:
    bool isAllDigitsSame(string s){
        for(int i=0;i<s.size()-1;i++){
            if(s[i]!=s[i+1]){
                return false;
            }
        }
        return true;
    }
    bool hasSameDigits(string s) {
        if(isAllDigitsSame(s)){
            return true;
        }
        while(s.size()>2){
            for(int i=1;i<s.size();i++){
                int first=(s[i-1]-'0');
                int second=(s[i]-'0');
                int value=(first+second)%10;
                s[i-1]=char(value+'0');
            }
            s.pop_back();
            if(isAllDigitsSame(s)){
                return true;
            }
        }
        return false;
    }
};