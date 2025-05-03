class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int groupNumber=0;
        vector<int>connectedNodes(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>maxDiff){
                groupNumber++;
            }
            connectedNodes[i]=groupNumber;
        }
        vector<bool>ans;
        for(auto &query:queries){
            int x=query[0];
            int y=query[1];
            ans.push_back(connectedNodes[x]==connectedNodes[y]);
        }
        return ans;
    }
};