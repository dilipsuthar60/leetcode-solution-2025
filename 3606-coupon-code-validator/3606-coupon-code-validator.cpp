class Solution {
public:
    bool isCouponValid(string &s){
        for(auto &ch: s){
            if(!(isalnum(ch) || ch=='_')){
                return false;
            }
        }
        return s.size()?true: false;
    }
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        vector<string>result;
        int n=code.size();
        vector<pair<int,string>>store;
        unordered_map<string,int>priority={
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3},
        };
        for(int i=0;i<n;i++){
            if(!isActive[i] || !isCouponValid(code[i]) || !priority.count(businessLine[i])){
                continue;
            }
            store.push_back({priority[businessLine[i]], code[i]});
        }
        sort(store.begin(),store.end());
        for(auto &[_,code]:store){
            result.push_back(code);
        }
        return result;
    }
};