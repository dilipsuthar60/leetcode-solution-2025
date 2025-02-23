class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int>pq;
        int index=0;
        for(auto &row:grid){
            sort(row.rbegin(),row.rend());
            for(int i=0;i<row.size()&&i<limits[index];i++){
                pq.push(row[i]);
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