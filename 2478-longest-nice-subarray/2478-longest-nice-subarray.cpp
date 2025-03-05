class Solution
{
    public:
    int n;
    bool check(vector<long long>&bit)
    {
        for(int i=0;i<32;i++)
        {
            if(bit[i]>=2)
            {
                return false;
            }
        }
        return true;
    }
    void update(vector<long long>&bit, int num, int value){
        for(int i=0;i<32;i++){
            if(num&(1<<i)){
                bit[i]+=value;
            }
        }
    }
    int longestNiceSubarray(vector<int> &nums)
    {
        n = nums.size();
        int j = 0;
        int ans = 1;
        vector < long long > bit(32, 0);
        for (int i = 0; i < n; i++)
        {
            update(bit,nums[i],1);
            while (j <= i && check(bit) == false)
            {
                update(bit,nums[j],-1);
                j++;
            }
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};