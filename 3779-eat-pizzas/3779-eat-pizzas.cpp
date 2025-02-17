class Solution {
public:
    long long maxWeight(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        sort(nums.rbegin(),nums.rend());
        int totalDays=n/4;
        int evenDays=totalDays/2;
        int oddDays=totalDays-evenDays;
        int index=0;
        for(int i=0;i<oddDays;i++){
            ans+=nums[index];
            index++;
        }
        index++;
        for(int i=0;i<evenDays;i++){
            ans+=nums[index];
            index+=2;
        }
        return ans;
    }
};