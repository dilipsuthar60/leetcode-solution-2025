class Solution {
public:
    void find(const string &s,int index,string &curr,vector<string>&ans,const string mp[]){
        if(index>=s.size()){
            if(curr.size()>=1)
            ans.push_back(curr);
            return ;
        }
        for(auto &it:mp[s[index]-'2']){
            curr.push_back(it);
            find(s,index+1,curr,ans,mp);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string mp[] = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string curr="";
        find(digits,0,curr,ans,mp);
        return ans;
    }
};