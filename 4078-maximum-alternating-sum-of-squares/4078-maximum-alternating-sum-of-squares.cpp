class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        for(auto &it:nums){
            it=abs(it);
        }
        multiset<long long>s(nums.begin(),nums.end());
        while(s.size()){
            int first=*s.rbegin();
            int second=0;
            s.erase(--s.end());
            if(s.size()){
                second=*s.begin();
                s.erase(s.begin());
            }
            ans+=((first*first)-(second*second));
        }
        return ans;
    }
};