class Solution {
public:
    bool maxSubstringLength(string s, int k) {
        int n=s.size();
        vector<int>left(26,n),right(26,-1),count(26,0);
        for(int i=0;i<n;i++){
            int index=s[i]-'a';
            if(left[index]==n){
                left[index]=i;
            }
            right[index]=i;
            count[index]++;
        }
        vector<vector<int>>validInterval;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(left[i]<=right[j]&&left[i]!=-1){
                    int cnt=0;
                    for(int x=0;x<26;x++){
                        if(left[i]<=left[x]&&right[x]<=right[j]){
                            cnt+=count[x];
                        }
                    }
                    if(cnt==(right[j]-left[i]+1)&&cnt<s.size()){
                        validInterval.push_back({left[i], right[j]});
                    }
                }

            }
        }
        sort(validInterval.begin(),validInterval.end(),[&](auto &a, auto &b){return a[1]<b[1];});
        int cnt = 0;
        int currend = -1;
        for (auto &i : validInterval) {
            if (i[0] > currend) {
                cnt++;
                currend = i[1];
            }
        }
        
        return cnt >= k;
    }
};