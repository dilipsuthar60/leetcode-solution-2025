class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int>twoNumberXor;
        unordered_set<int>threeNumberXor;
        int n=nums.size();
        if(n<=2) return n;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                twoNumberXor.insert(nums[i]^nums[j]);
            }
        }

        for(auto &it:twoNumberXor){
            for(int i=0;i<n;i++){
                threeNumberXor.insert(it^nums[i]);
            }
        }
        return threeNumberXor.size();
    }
};