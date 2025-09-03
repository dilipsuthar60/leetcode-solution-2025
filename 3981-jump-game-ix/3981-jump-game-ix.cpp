class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixMax(n), suffixMin(n);
        prefixMax[0]=nums.front();
        for(int i=1;i<n;i++){
            prefixMax[i]=max(prefixMax[i-1],nums[i]);
        }

        suffixMin[n-1]=nums.back();
        for(int i=n-2;i>=0;i--){
            suffixMin[i]=min(suffixMin[i+1],nums[i]);
        }
        vector<int>ans(n);
        for(int i=n-1;i>=0;i--){
            ans[i]=prefixMax[i];
            if(i+1<n&&prefixMax[i]>suffixMin[i+1]){
                ans[i]=ans[i+1];
            }
        }
        return ans;
    }
};