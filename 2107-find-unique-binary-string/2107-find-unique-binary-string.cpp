class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) 
    {
        int n=nums.size();
        unordered_set<string>s(nums.begin(),nums.end());
        for(int i=0;i<(1<<n);i++)
        {
            string str="";
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    str+='1';
                }
                else
                {
                    str+='0';
                }
            }
            if(s.find(str)==s.end())
            {
                return str;
            }
        }
        return "";
    }
};