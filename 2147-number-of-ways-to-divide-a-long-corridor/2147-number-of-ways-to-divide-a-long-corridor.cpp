class Solution {
public:
    int cache[100005][3];
    const int mod=1e9+7;
    int find(string &s, int index, int seatCounter){
        if(index>=s.size()){
            return seatCounter>=2?1:0;
        }
        if(cache[index][seatCounter]!=-1){
            return cache[index][seatCounter]%mod;
        }
        long long ans=0;
        if(seatCounter>=2){
            if(s[index]=='S'){
                ans+=find(s, index+1, 1);
            }
            else{
                ans+=find(s, index+1, 0)+find(s,index+1,seatCounter);
            }
        }
        else{
            if(s[index]=='S'){
                ans+=find(s,index+1, seatCounter+1);
            }
            else{
                ans+=find(s,index+1, seatCounter);
            }
        }
        return cache[index][seatCounter]= ans%mod;
    }
    int numberOfWays(string corridor) {
        memset(cache,-1,sizeof(cache));
        return find(corridor, 0, 0);
    }
};