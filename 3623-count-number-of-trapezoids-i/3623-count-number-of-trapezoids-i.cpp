class Solution {
public:
    const int mod=1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int>mp;
        for(auto &point:points){
            mp[point[1]]++;
        }
        long long result=0;
        long long prev=0;
        for(auto &[_,point]:mp){
            long long line=1ll*point*(point-1)/2;
            result+=(line*prev);
            result%=mod;
            prev+=line;
        }
        return result;
    }
};