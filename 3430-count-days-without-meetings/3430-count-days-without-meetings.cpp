class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int size=meetings.size();
        sort(meetings.begin(),meetings.end());
        vector<vector<int>>mergeList;
        mergeList.push_back(meetings.front());
        for(int i=1;i<size;i++){
            if(mergeList.back()[1]<meetings[i][0]){
                mergeList.push_back(meetings[i]);
            }
            else{
                mergeList.back()[1]=max(mergeList.back()[1],meetings[i][1]);
            }
        }
        int busyDays=0;
        for(auto &it:mergeList){
            busyDays+=(it[1]-it[0]+1);
        }
        return days-busyDays;
    }
};