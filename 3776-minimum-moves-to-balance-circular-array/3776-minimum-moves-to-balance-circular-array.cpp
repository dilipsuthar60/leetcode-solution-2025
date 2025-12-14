class Solution {
public:
    long long minMoves(vector<int>& balance) {
        int n=balance.size();
        long long totalMoves=0;
        long long sum=accumulate(balance.begin(),balance.end(),0ll);
        if(sum<0) return -1;
        int negativeIndex=-1;
        for(int i=0;i<n;i++){
            if(balance[i]<0){
                negativeIndex=i;
            }
        }
        if(negativeIndex==-1) return 0;
        int distance=1;
        while(balance[negativeIndex]<0){
            int leftIndex=(negativeIndex-distance+n)%n;
            int rightIndex=(negativeIndex+distance)%n;
            long long leftRightSum=balance[leftIndex]+balance[rightIndex];
            long long need = -1*balance[negativeIndex];
            balance[negativeIndex]+=min(need,leftRightSum);
            totalMoves+=distance*min(need,leftRightSum);
            distance++;
        }
        return totalMoves;
    }
};