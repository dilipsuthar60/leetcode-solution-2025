class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,vector<int>>row,col;
        for(auto &it:buildings){
            int x=it[0], y=it[1];
            row[x].push_back(y);
            col[y].push_back(x);
        }
        for(auto &[key,value]:row){
            sort(value.begin(),value.end());
        }
        for(auto &[key,value]:col){
            sort(value.begin(),value.end());
        }
        int count=0;
        for(auto &it:buildings){
            int x=it[0], y=it[1];
            auto &nums1=row[x];
            auto &nums2=col[y];
            int index1=lower_bound(nums1.begin(),nums1.end(),y)-nums1.begin();
            bool isLeft = (index1>0);
            bool isRight = (index1+1<nums1.size());
            int index2=lower_bound(nums2.begin(),nums2.end(),x)-nums2.begin();
            bool isDown = (index2>0);
            bool isUp= (index2+1<nums2.size());
            if(isLeft&&isRight&&isDown&&isUp){
                count++;
            }
        }
        return count;
    }
};