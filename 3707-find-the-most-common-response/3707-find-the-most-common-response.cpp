class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string,int>mp;
        for(auto &response:responses){
            unordered_set<string>s;
            for(auto &value:response){
                s.insert(value);
            }
            for(auto &it:s){
                mp[it]++;
            }
        }
        int maxValue=0;
        string maxResponseType="";
        for(auto &[key,value]:mp){
            if(maxValue<value){
                maxValue=value;
                maxResponseType =key;
            }
            else if(maxValue==value){
                maxResponseType=min(maxResponseType, key);
            }
        }
        return maxResponseType;
    }
};