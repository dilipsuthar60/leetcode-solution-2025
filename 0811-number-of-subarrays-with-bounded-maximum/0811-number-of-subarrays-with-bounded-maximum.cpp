class Solution {
public:
    int find(vector<int>&nums,int x)
    {
        int j=0;
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>x)
            {
                j=i+1;
                continue;
            }
            count+=i-j+1;
        }
        return count;
    }
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        return find(nums,right)-find(nums,left-1);
    }
};