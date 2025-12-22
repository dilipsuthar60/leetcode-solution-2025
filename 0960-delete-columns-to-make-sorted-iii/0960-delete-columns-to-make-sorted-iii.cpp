class Solution {
public:
    int ok(int i, int j, vector<string>&strs){
        for(int k=0;k<strs.size();k++){
            if(strs[k][i]<strs[k][j]){
                return false;
            }
        }
        return true;
    }
    int minDeletionSize(vector<string>& strs) {
        int rowLength=strs.size();
        int colLength=strs[0].size();
        vector<int>dp(colLength,1);
        for(int i=0;i<colLength;i++){
            for(int j=0;j<i;j++){
                if(ok(i,j,strs)){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return colLength-*max_element(dp.begin(),dp.end());
    }
};