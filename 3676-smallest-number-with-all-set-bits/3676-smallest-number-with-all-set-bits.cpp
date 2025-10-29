class Solution {
public:
    int smallestNumber(int n) {
        for(int i=0;i<32;i++){
            if(n<=((1<<i)-1)){
                return (1<<i)-1;
            }
        }
        return 90;
    }
};