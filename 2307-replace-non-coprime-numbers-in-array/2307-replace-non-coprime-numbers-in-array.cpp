class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>result;
        for(auto &num: nums){
            while(true){
                int lastElement=(result.size())?result.back():1;
                int currentGcd=__gcd(lastElement, num);
                if(currentGcd==1) break;
                num=(lastElement/currentGcd)*num;
                result.pop_back();
            }
            result.push_back(num);
        }
        return result;
    }
};