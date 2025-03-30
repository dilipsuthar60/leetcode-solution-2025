class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat)
    {
        int d=0;
        int x=0;
        int y=0;
        int nx=0;
        int ny=0;
        int n=mat.size();
        int m=mat[0].size();
        vector<int>ans;
        vector<pair<int,int>>dir={{0,1},{1,0},{0,-1},{-1,0}};
        auto is_safe=[&]()
        {
          if(nx>=0&&ny>=0&&nx<n&&ny<m&&mat[nx][ny]!=1e9)
          {
              return true;
          }
            return false;
        };
        for(int i=0;i<n*m;i++)
        {
            nx=x+dir[d].first;
            ny=y+dir[d].second;
            if(!is_safe())
            {
                d=(d+1)%4;
                nx=x+dir[d].first;
                ny=y+dir[d].second;
            }
            ans.push_back(mat[x][y]);
            mat[x][y]=1e9;
            x=nx;
            y=ny;
        }
        return ans;
    }
};