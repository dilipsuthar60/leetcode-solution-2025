class Solution {
public:
    int totalMoney(int n) {
        int amount=0;
        for(int i=0, start=0, startPoint=0;i<n;i++){
            if(i%7==0){
                startPoint++;
                start=startPoint;
            }
            amount+=start;
            start++;
        }
        return amount;
    }
};