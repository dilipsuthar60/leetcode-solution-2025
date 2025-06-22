class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        vector<string>ans;
        for(int i=0;i<s.size();i+=k){
            // cout<<s.substr(i,k)<<endl;
            ans.push_back(s.substr(i,k));
        }
        while(ans.back().size()!=k){
            ans.back()+=fill;
        }
        return ans;
    }
};