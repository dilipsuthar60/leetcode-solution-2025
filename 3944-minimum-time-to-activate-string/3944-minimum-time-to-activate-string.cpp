class Solution {
public:
    bool find(string s, vector<int>&order, int time, int k){
        int n=s.size();
        for(int i=0;i<=time;i++){
            s[order[i]]='*';
        }
        long totalSubstring=1ll*n*(n+1)/2;
        long invaildSubstring=0, len=0;
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                invaildSubstring+=(len*(len+1)/2);
                len=0;
            }
            else{
                len++;
            }
        }
        invaildSubstring+=(len*(len+1)/2);
        long totalVaildSubstringWithStar=totalSubstring-invaildSubstring;
        return totalVaildSubstringWithStar>=k;
    }
    int minTime(string s, vector<int>& order, int k) {
        int l=0, r=order.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(find(s, order,mid, k)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};