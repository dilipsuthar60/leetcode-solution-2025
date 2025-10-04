class Solution {
public:
    int distinctPoints(string s, int k) {
        int n=s.size();
        vector<pair<int,int>>prefix(n+1, {0,0});
        for(int i=1;i<=n;i++){
            prefix[i].first = prefix[i-1].first;
            prefix[i].second = prefix[i-1].second;
            if(s[i-1]=='U'){
                prefix[i].second++;
            }
            else if(s[i-1]=='D'){
                prefix[i].second--;
            }
            else if(s[i-1]=='L'){
                prefix[i].first--;
            }
            else{
                prefix[i].first++;
            }
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