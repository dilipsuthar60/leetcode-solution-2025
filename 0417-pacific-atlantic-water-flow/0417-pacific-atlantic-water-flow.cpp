class Solution {
public:
    vector<pair<int,int>>d={{-1,0},{1,0},{0,-1},{0,1}};
    void find(vector<vector<int>>&mat,int i,int j,vector<vector<int>>&blue)
    {
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        blue[i][j]=1;
        while(q.size())
        {
            auto temp=q.front();
            q.pop();
            int x=temp.first;
            int y=temp.second;
            for(auto it:d)
            {
                int nx=x+it.first;
                int ny=y+it.second;
                if(nx>=0&&ny>=0&&nx<n&&ny<m&&mat[nx][ny]>=mat[x][y]&&blue[nx][ny]==0)
                {
                    blue[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& mat)
    {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>blue(n,vector<int>(m,0));
        vector<vector<int>>red(n,vector<int>(m,0));
        int f=0;
        for(int round=0;round<2;round++)
        {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i==0||j==0)&&f==1)
                {
                    find(mat,i,j,blue);
                }
                if((i==n-1||j==m-1)&&f==0)
                {
                    find(mat,i,j,red);
                }
            }
        }
            f=1;
        }
        vector<vector<int>>v;
     
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(blue[i][j]&&red[i][j])
                {
                    v.push_back({i,j});
                }
            }
        }
        return v;
    }
};