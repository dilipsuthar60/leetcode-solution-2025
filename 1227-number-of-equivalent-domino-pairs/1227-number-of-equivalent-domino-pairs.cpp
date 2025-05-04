class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int size=dominoes.size();
        map<pair<int,int>,int>mp;
        int count=0;
        for(int i=0;i<size;i++){
            int a=min(dominoes[i][0], dominoes[i][1]);
            int b=max(dominoes[i][0], dominoes[i][1]);
            if(mp.find({a,b})!=mp.end()){
                count+=mp[{a,b}];
            }
            mp[{a,b}]++;
        }
        return count;
    }
};