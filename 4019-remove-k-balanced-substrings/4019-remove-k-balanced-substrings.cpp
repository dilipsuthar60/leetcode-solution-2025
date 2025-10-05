class Solution {
public:
    string removeSubstring(string s, int k) {
        int n=s.size();
        vector<pair<char,int>>stack;
        for(int i=0;i<n;i++){
            if(stack.size()&&stack.back().first==s[i]){
                stack.back().second++;
            }
            else{
                stack.push_back({s[i],1});
            }
            if(stack.size()>1){
                auto firstTop=stack.back();
                stack.pop_back();
                auto secondTop=stack.back();
                stack.pop_back();
                if(secondTop.first=='('&& firstTop.first==')'&&firstTop.second>=k&&secondTop.second>=k){
                    firstTop.second-=k;
                    secondTop.second-=k;
                }
                if(secondTop.second) stack.push_back(secondTop);
                if(firstTop.second) stack.push_back(firstTop);
            }
        }
        string result="";
        for(auto &it:stack){
            result+=string(it.second,it.first);
        }
        return result;
    }
};