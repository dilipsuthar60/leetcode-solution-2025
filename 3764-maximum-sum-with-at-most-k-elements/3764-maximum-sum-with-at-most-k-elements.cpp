class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int> pq;
        for (int i=0;i<grid.size();i++) {
            sort(grid[i].rbegin(), grid[i].rend());
            for (int j = 0; j < grid[i].size() && j < limits[i]; j++) {
                pq.push(grid[i][j]);
            }
        }
        long long ans = 0;
        while (pq.size() &&k--) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};