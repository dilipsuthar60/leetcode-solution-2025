class Solution {
public:
    vector<int> partitionLabels(string s) {
       vector<int>ans;
       unordered_map<char,int>mp;
       for(int i=0;i<s.size();i++) mp[s[i]]=i;
       int last=0;
       int mx=0;
       for(int i=0;i<s.size();i++){
         mx=max(mx,mp[s[i]]);
         if(mx==i){
            ans.push_back(i-last+1);
            last=i+1;
         }
       }
       return ans;
    }
};