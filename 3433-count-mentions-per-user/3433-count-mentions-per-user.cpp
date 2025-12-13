class Solution {
public:
    void applyMessaageEvent(vector<string>&event, vector<int>&offine, vector<int>&mentionUser){
        vector<string>ids;
        istringstream ss(event[2]);
        string token;
        int timeStamp=stoi(event[1]);
        while(ss>>token){
            ids.push_back(token);
        }
        for(auto &id: ids){
            if(id=="ALL"){
                for(int i=0;i<mentionUser.size();i++){
                    mentionUser[i]++;
                }
            }
            else if(id=="HERE"){
                for(int i=0;i<mentionUser.size();i++){
                    if(offine[i]==0|| (offine[i]+60)<=timeStamp){
                        mentionUser[i]++;
                    }
                }
            }
            else{
                mentionUser[stoi(id.substr(2))]++;
            }
        }
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(),events.end(), [&](auto &a, auto &b){
            int t1=stoi(a[1]);
            int t2=stoi(b[1]);
            if(t1==t2){
                return a[0][0]>b[0][0];
            }
            return t1<t2;
        });

        vector<int>offine(numberOfUsers,0);
        vector<int>mentionUser(numberOfUsers,0);
        for(auto &event:events){
            if(event[0]=="MESSAGE"){
                applyMessaageEvent(event, offine, mentionUser);
            }
            else{
                offine[stoi(event[2])]=stoi(event[1]);
            }
        }
        return mentionUser;
    }
};