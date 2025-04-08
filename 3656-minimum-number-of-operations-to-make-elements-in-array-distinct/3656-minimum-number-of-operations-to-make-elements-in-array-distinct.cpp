class Solution
{
    public: int minimumOperations(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int>s;
        for(int i=n-1;i>=0;i--){
            if(s.find(nums[i])!=s.end()){
                return i/3+1;
            }
            s.insert(nums[i]);
        }
        return 0;
    }
};