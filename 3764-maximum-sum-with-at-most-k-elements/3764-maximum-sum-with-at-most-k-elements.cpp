class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        int index=0;
        for(auto &row:grid){
            sort(row.rbegin(),row.rend());
            for(int i=0;i<row.size()&&i<limits[index];i++){
                pq.push(row[i]);
                if(pq.size()>k){
                    pq.pop();
                }
            }
            index++;
        }
        long long ans=0;
        while(pq.size()&&k){
            ans+=pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};