class Solution {
public:
    long long dp[51][51][51];
    const int mod=1e9+7;
    int find(int i,int j, int k,int n, int m){
        long long ans=0;
        if(k<0) return 0;
        if(i<0|| j<0|| i>=n||j>=m){
            return 1;
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k]%mod;
        }
        ans+=find(i+1,j,k-1,n,m);
        ans+=find(i-1,j,k-1,n,m);
        ans+=find(i,j+1,k-1,n,m);
        ans+=find(i,j-1,k-1,n,m);
        return dp[i][j][k]= ans%mod;;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        return find(startRow, startColumn, maxMove, m,n);
    }
};