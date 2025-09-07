class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>ans(n,0);
        for(int i=0,j=n-1,start=1;i<j;i++,j--, start++){
            ans[i]=start;
            ans[j]=-start;
        }
        return ans;
    }
};