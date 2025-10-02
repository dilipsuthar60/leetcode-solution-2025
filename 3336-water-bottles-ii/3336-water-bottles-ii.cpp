class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange){
            numBottles-=(numExchange);
            numBottles++;
            ans++;
            numExchange++;
        }
        return ans;
    }
};