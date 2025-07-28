class Solution {
public:
    vector<pair<int,int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
    int find(vector<vector<int>>&mat, int i,int j, int k){
        if(i<0||j<0||i>=mat.size()||j>=mat[0].size()||!mat[i][j]){
            return 0;
        }
        int ans=mat[i][j]%k;
        mat[i][j]=0;
        for(auto &direction: directions){
            int nx=i+direction.first;
            int ny=j+direction.second;
            ans+=find(mat, nx, ny, k);
        }
        return ans%k;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j]) continue;
                count+=(find(grid,i,j,k)==0);
            }
        }
        return count;
    }
};