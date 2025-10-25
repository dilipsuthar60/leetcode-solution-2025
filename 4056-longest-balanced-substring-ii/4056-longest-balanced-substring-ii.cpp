class Solution {
public:
    int cal1(string &s){
        int count=1;
        int ans=1;
        for(int i=1, n=s.size();i<n;i++){
            if(s[i-1]==s[i]){
                count++;
            }
            else{
                count=1;
            }
            ans=max(ans,count);
        }
        return ans;
    }
    int cal2(string &s, char a, char b){
        int n=s.size();
        unordered_map<int,int>mp;
        mp[0]=-1;
        int ans=0, count=0;
        for(int i=0;i<n;i++){
            if(s[i]==a){
                count++;
            }
            else if(s[i]==b){
                count--;
            }
            else{
                mp.clear();
                mp[0]=i;
                count=0;
            }
            if(mp.find(count)!=mp.end()){
                ans=max(ans,i-mp[count]);
            }
            else
            mp[count]=i;
        }
        return ans;
    }
    int cal3(string &s){
        int n=s.size(), ans=0;
        map<pair<int,int>,int>mp;
        int a=0,b=0,c=0;
        mp[{0,0}]=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='a'){
                a++;
            }
            else if(s[i]=='b'){
                b++;
            }
            else {
                c++;
            }
            if(mp.find({a-b,c-b})!=mp.end()){
                ans=max(ans,i-mp[{a-b, c-b}]);
            }
            else{
                mp[{a-b, c-b}]=i;
            }
        }
        return ans;
    }
    int longestBalanced(string s) {
        int first=cal1(s);
        int third=cal3(s);
        int second=max({cal2(s,'a','b'),cal2(s,'b','c'), cal2(s,'c','a')});
        return max({first,second,third});
    }
};