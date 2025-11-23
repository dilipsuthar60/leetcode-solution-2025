class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {
        int n=nums.size(), maximumLength=0;
        unordered_map<string,int>mp;
        mp["0#0"]=-1;
        for(int i=0,currentXor=0, balance=0;i<n;i++){
            balance+=(nums[i]%2==0?1:-1);
            currentXor^=nums[i];
            string hashKey=to_string(currentXor)+"#"+to_string(balance);
            if(mp.find(hashKey)!=mp.end()){
                maximumLength=max(maximumLength, i-mp[hashKey]);
            }
            else{
                mp[hashKey]=i;
            }
        }
        return maximumLength;
    }
};