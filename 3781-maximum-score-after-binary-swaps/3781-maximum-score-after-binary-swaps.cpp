class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long result=0;
        priority_queue<int>pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(s[i]=='1'){
                result+=pq.top();
                pq.pop();
            }
        }
        return result;
    }
};