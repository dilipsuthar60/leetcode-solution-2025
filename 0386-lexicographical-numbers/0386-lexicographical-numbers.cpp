class Solution {
public:
    void find(int x,int n,vector<int>&v)
    {
        if(x>n)
        {
            return ;
        }
        v.push_back(x);
        for(int i=0;i<=9;i++)
        {
            find(x*10+i,n,v);
        }
    }
    vector<int> lexicalOrder(int n)
    {
        vector<int>v;
        for(int i=1;i<=9;i++)
        {
            find(i,n,v);
        }
        return v;
    }
};