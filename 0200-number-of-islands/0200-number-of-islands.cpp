class Solution {
public:
    vector<pair<int,int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
    void find(vector<vector<char>>&grid,int i,int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[0].size()||grid[i][j]=='0'){
            return ;
        }
        grid[i][j]='0';
        for(auto &it:direction){
            int nx =i+it.first;
            int ny =j+it.second;
            find(grid,nx,ny);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    find(grid,i,j);
                    count++;
                }
            }
        }
        return count;
    }
};