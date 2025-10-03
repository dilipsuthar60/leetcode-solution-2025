class Solution {
public:
    bool isSafe(int x, int y, int n, int m){
        return x>=0&&y>=0&&x<n&&y<m;
    }
    int trapRainWater(vector<vector<int>>& mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        using pp = pair<int,pair<int,int>>;
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        vector<vector<bool>>visited(n,vector<bool>(m));
        vector<pair<int,int>>direction={{-1,0},{1,0},{0,-1},{0,1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    pq.push({mat[i][j],{i,j}});
                    visited[i][j]=true;
                }
            }
        }
        int totalTrappingWater=0;
        while(pq.size()){
            auto [cost, cordinate]=pq.top();
            pq.pop();
            for(auto &[x,y]:direction){
                int nx=x+cordinate.first;
                int ny=y+cordinate.second;
                if(isSafe(nx,ny, n, m)&&!visited[nx][ny]){
                    totalTrappingWater+=max(0,cost-mat[nx][ny]);
                    visited[nx][ny]=true;
                    pq.push({max(cost, mat[nx][ny]), {nx,ny}});
                }
            }
        }
        return totalTrappingWater;
    }
};