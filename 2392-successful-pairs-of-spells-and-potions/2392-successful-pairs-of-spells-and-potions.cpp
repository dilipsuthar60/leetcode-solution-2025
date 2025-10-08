class Solution {
public:
    int find(vector<int>&nums,long long success, long long factor){
        int n=nums.size();
        int l=0,r=n-1;
        long long index=n;
        while(l<=r){
            long long mid=(l+r)/2;
            if(factor*nums[mid]>=success){
                index= mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return n-index;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        vector<int>ans(n,0);
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            ans[i]=find(potions, success, spells[i]);
        }
        return ans;
    }
};