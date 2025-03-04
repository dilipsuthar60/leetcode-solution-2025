class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int>nums;
        int index=0;
        while(pow(3,index)<=n){
            nums.push_back(pow(3,index));
            index++;
        }
        for(int i=nums.size()-1;i>=0;i--){
            if(n>=nums[i]){
                n-=nums[i];
            }
        }
        return n==0;
    }
};