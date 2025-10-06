class Solution {
public:
    bool isSafe(int x, int y, int n, vector<vector<bool>>&visited){
        return x>=0&&y>=0&&x<n&&y<n&&(!visited[x][y]);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        vector<vector<bool>>visited(n,vector<bool>(n));
        pq.push({grid[0][0],0,0});
        visited[0][0]=true;
        vector<pair<int,int>>directions={{-1,0},{1,0},{0,-1},{0,1}};
        int ans=0;
        while(pq.size()){
            auto temp=pq.top();
            pq.pop();
            int cost=temp[0],x=temp[1],y=temp[2];
            ans=max(ans,cost);
            if(x==n-1&&y==n-1){
                return ans;
            }
            for(auto &direction:directions){
                int nx=x+direction.first;
                int ny=y+direction.second;
                if(isSafe(nx,ny,n,visited)){
                    pq.push({grid[nx][ny],nx,ny});
                    visited[nx][ny]=true;
                }
            }

        }
        return ans;
    }
};