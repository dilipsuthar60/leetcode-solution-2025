class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector<int>v;
        for(int i=0, n=nums.size();i<n;i++){
            if(nums[i]==1){
                v.push_back(i);
            }
        }
        for(int i=1;i<v.size();i++){
            if(v[i]-v[i-1]<=k){
                return false;
            }
        }
        return true;
    }
};