class Solution {
public:
    int candy(vector<int>& nums)
    {
        int n=nums.size();
        vector<int>left(n,1),right(n,1);
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
            {
                left[i]=left[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]>nums[i+1])
            {
                right[i]=right[i+1]+1;
            }
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=max(left[i],right[i]);
        }
        return sum;
    }
};