class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        string maxStr="",minStr="";
        char firstElement='#';
        for(int i=0;i<s.size();i++){
            if(s[i]!='9'){
                firstElement=s[i];
                break;
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]==firstElement){
                maxStr+='9';
            }
            else{
                maxStr+=s[i];
            }
        }

        for(int i=0;i<s.size();i++){
            if(s[i]==s[0]){
                minStr+='0';
            }
            else{
                minStr+=s[i];
            }
        }
        return stoi(maxStr)-stoi(minStr);
    }
};