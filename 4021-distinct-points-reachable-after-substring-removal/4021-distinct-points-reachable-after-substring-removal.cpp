class Solution {
public:
    pair<int,int>getMovePosition(char ch){
        if(ch=='U') return {0,1};
        if(ch=='D') return {0,-1};
        if(ch=='L') return {-1, 0};
        return {1, 0};
    }
    int distinctPoints(string s, int k) {
        int n=s.size();
        vector<pair<int,int>>prefix(n+1, {0,0});
        for(int i=1;i<=n;i++){
            auto position=getMovePosition(s[i-1]);
            prefix[i].first = prefix[i-1].first+position.first;
            prefix[i].second = prefix[i-1].second+position.second;
        }
        int totalX=prefix.back().first;
        int totalY=prefix.back().second;
        set<pair<int,int>>visited;
        for(int i=0;i<=n-k;i++){
            int x=totalX-prefix[i+k].first+prefix[i].first;
            int y=totalY-prefix[i+k].second+prefix[i].second;
            visited.insert({x,y});
        }
        return visited.size();
    }
};