class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        vector<int>rowMin(n+1,1e9),rowMax(n+1,-1e9), colMin(n+1,1e9),colMax(n+1,-1e9);
        for(int i=0;i<buildings.size();i++){
            int x=buildings[i][0];
            int y=buildings[i][1];
            colMin[y]=min(colMin[y], x);
            colMax[y]=max(colMax[y], x);
            rowMin[x]=min(rowMin[x], y);
            rowMax[x]=max(rowMax[x], y);
        }
        int counter=0;
        for(auto &building: buildings){
            int x=building[0];
            int y=building[1];
            if(rowMin[x]<y&&rowMax[x]>y&&colMin[y]<x&&colMax[y]>x){
                counter++;
            }
        }
        return counter;
    }
};