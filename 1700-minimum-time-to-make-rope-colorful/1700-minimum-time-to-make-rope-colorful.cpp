class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int minCost=0;
        stack<char>s;
        for(int i=1;i<colors.size();i++){
            if(colors[i]==colors[i-1]){
                int currentMinCost=min(neededTime[i],neededTime[i-1]);
                minCost+=currentMinCost;
                if(currentMinCost==neededTime[i]){
                    swap(neededTime[i],neededTime[i-1]);
                }
            }
        }
        return minCost;
    }
};