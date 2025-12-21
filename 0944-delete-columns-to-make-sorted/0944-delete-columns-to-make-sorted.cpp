class Solution {
public:
    bool isInvalid(string &s){
        for(int i=0;i+1<s.size();i++){
            if(s[i]>s[i+1]){
                return true;
            }
        }
        return false;
    }
    int minDeletionSize(vector<string>& strs) {
        int length=strs.front().size();
        int result=0;
        for(int col=0;col<length;col++){
            string s;
            for(int row=0;row<strs.size();row++){
                s+=strs[row][col];
            }
            result+=isInvalid(s);
        }
        return result;
    }
};