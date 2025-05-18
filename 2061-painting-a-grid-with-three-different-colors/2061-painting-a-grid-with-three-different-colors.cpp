class Solution {
public:
    int mod=1e9+7;
    long long dp[1001][(1<<6)+1];
    vector<vector<int>>result;
    void allColor(vector<int>&nums,int index,int m,vector<int>curr)
    {
        if(index==m)
        {
            result.push_back(curr);
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(curr.size()==0||curr.back()!=nums[i])
            {
                curr.push_back(nums[i]);
                allColor(nums,index+1,m,curr);
                curr.pop_back();
            }
        }
    }
    long long find(vector<vector<int>>&result,int curr,int index,int &n)
    {
        if(index==n)
        {
            return 1;
        }
        if(dp[index][curr]!=-1)
        {
            return dp[index][curr]%mod;
        }
        long long ans=0;
        for(int i=0;i<result.size();i++)
        {
            int yes=1;
            for(int j=0;j<result[0].size();j++)
            {
                if(result[curr][j]==result[i][j])
                {
                    yes=0;
                    break ;
                }
            }
            if(yes)
            {

                ans+=find(result,i,index+1,n);
            }
        }
        return dp[index][curr]=ans%mod;
    }
    int colorTheGrid(int m, int n) {
        memset(dp,-1,sizeof(dp));
        vector<int>nums={1,2,3};
        vector<int>curr;
        allColor(nums,0,m,curr);
        long long ans=0;
        for(int i=0;i<result.size();i++)
        {
            ans+=find(result,i,1,n);
            ans%=mod;
        }
        return (int)ans;
    }
};