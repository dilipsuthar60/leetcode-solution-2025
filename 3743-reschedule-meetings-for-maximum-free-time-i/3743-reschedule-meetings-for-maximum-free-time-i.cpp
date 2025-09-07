class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=startTime.size();
        vector<int>freeTime;
        freeTime.push_back(startTime[0]);
        for(int i=0;i+1<n;i++){
            freeTime.push_back(startTime[i+1]-endTime[i]);
        }
        freeTime.push_back(eventTime-endTime.back());
        int takeFreeSlot=k+1;
        int ans =0;
        int currentSum=0;
        for(int i=0;i<takeFreeSlot;i++){
            currentSum+=freeTime[i];
        }
        ans=currentSum;
        for(int i=takeFreeSlot;i<freeTime.size();i++){
            currentSum+=(freeTime[i]-freeTime[i-takeFreeSlot]);
            ans=max(ans,currentSum);
        }
        return ans;
    }
};