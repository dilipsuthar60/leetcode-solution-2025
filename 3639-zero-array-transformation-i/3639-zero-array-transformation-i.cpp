class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>prefix(n+1,0);
        for(auto &query:queries){
            prefix[query[0]]++;
            prefix[query[1]+1]--;
        }
        for(int i=1;i<n;i++){
            prefix[i]+=prefix[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]>prefix[i]){
                 return false;
            }
        }
        return true;
    }
};