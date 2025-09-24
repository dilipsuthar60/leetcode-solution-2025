class Solution {
public:
    string fractionToDecimal(int num, int den) 
    {
        if(num==0)
            return "0";
        string s;
        if(num>0^den>0)
        {
            s=s+"-";
        }
        long n=labs(num);
        long d=labs(den);
        long r,q;
        q=n/d;
        r=n%d;
        s=s+to_string(q);
        if(r==0)
            return s;
        else
        {
            s=s+".";
            unordered_map<long,int>mp;
            while(r!=0)
            {
                if(mp.find(r)!=mp.end())
                {
                    int len=mp[r];
                    s.insert(len,"(");
                    s=s+")";
                    break;
                }
                else
                {
                    mp[r]=s.size();
                    r=r*10;
                    q=r/d;
                    r=r%d;
                    s=s+to_string(q);
                }
            }
        }
        return s;
    }
};