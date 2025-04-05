class Solution {
public:
    int subsetXORSum(vector<int>& nums) 
    {
        int sum=0;
        int n=nums.size();
        for(int i=1;i<(1<<n);i++)
        {
            int x=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    x=x^nums[j];
                }
            }
            sum+=x;
        }
        return sum;
    }
};