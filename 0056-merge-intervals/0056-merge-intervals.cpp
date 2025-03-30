class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size=intervals.size();
        vector<vector<int>>mergeInterval;
        sort(intervals.begin(),intervals.end());
        mergeInterval.push_back(intervals.front());
        for(int i=1;i<size;i++){
            if(mergeInterval.back()[1]<intervals[i][0]){
                mergeInterval.push_back(intervals[i]);
            }
            else{
                mergeInterval.back()[1]=max(mergeInterval.back()[1], intervals[i][1]);
            }
        }
        return mergeInterval; 
    }
};