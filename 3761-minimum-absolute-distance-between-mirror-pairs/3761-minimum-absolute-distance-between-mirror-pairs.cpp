class Solution {
public:
    int reverse(int n){
        int rev=0;
        while(n){
            rev=rev*10+n%10;
            n/=10;
        }
        return rev;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans=1e9,n=nums.size();
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                ans=min(ans,abs(i-mp[nums[i]]));
            }
            mp[reverse(nums[i])]=i;
        }
        return ans==1e9?-1:ans;
    }
};