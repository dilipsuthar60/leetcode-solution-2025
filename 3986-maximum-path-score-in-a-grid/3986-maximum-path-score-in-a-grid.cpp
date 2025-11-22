class Solution {
public:
    int n, m;
    int find(vector<vector<int>>&mat, int i, int j,int k, auto &dp){
        if(i==n||j==m){
            return INT_MIN;
        }
        int currentCost=0, currentScore=0;
        if(mat[i][j]==1){
            currentCost++;
            currentScore++;
        }
        if(mat[i][j]==2){
            currentCost++;
            currentScore+=2; 
        }
        if(k<currentCost){
            return INT_MIN;
        }
        if(i==n-1&&j==m-1){
            return mat[i][j];
        }
        if(dp[i][j][k]!=-1){
            return dp[i][j][k];
        }
        int left=currentScore+find(mat,i+1,j,k-currentCost, dp);
        int right=currentScore+find(mat,i,j+1,k-currentCost, dp);
        return dp[i][j][k]= max(left,right);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        int result=find(grid, 0,0,k, dp);
        return result<0?-1:result;
    }
};