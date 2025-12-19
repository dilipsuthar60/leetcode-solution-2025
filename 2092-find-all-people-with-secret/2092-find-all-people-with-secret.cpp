class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int,int>>dp[n+1];
        for(auto &meeting:meetings){
            dp[meeting[0]].push_back({meeting[1],meeting[2]});
            dp[meeting[1]].push_back({meeting[0],meeting[2]});
        }
        vector<bool>visited(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        pq.push({0,firstPerson});
        while(pq.size()){
            auto [time,parentNode]=pq.top();
            pq.pop();
            if(visited[parentNode]){
                continue;
            }
            visited[parentNode]=true;
            for(auto &[childNode, currentTime]:dp[parentNode]){
                if(time<=currentTime){
                    pq.push({currentTime, childNode});
                }
            }
        }
        vector<int>result;
        for(int i=0;i<n;i++){
            if(visited[i]) result.push_back(i);
        }
        return result;
    }
};