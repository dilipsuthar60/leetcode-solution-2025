class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n=nums.size();
        multiset<long long>s;
        long long cost=0;
        for(auto &element:nums) s.insert(element);
        while(s.size()){
            int firstElement=*s.begin();
            s.erase(s.begin());
            int thirdElement=*s.rbegin();
            s.erase(--s.end());
            int secondElement=*s.rbegin();
            s.erase(--s.end());
            cost+=secondElement;
        }
        return cost;
    }
};