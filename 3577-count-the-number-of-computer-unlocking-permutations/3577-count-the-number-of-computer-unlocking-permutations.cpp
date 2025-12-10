class Solution {
public:
    const int mod=1e9+7;
    int countPermutations(vector<int>& complexity) {
        int firstUnlocked=complexity.front();
        int minimumValue=*min_element(complexity.begin()+1,complexity.end());
        if(firstUnlocked>=minimumValue){
            return 0;
        }
        long fact=1;
        for(int i=1;i<complexity.size();i++){
            (fact*=i)%=mod;
        }
        return fact;
    }
};