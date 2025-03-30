class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJump=nums[0];
        for(int i=1;i<nums.size();i++){
            if(i>maxJump) return false;
            maxJump=max(maxJump,nums[i]+i);
        }
        return true;
    }
};