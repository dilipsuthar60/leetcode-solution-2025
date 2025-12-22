class Solution {
public:
    vector<int>dp[100005];
    int n;
    int bfs1(int node){
        queue<int>q;
        q.push(node);
        int farthest=node;
        vector<int>visited(n);
        visited[node]=1;
        while(q.size()){
            for(int i=q.size();i>0;i--){
                int temp=q.front();
                q.pop();
                farthest=temp;
                for(auto &it:dp[temp]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it]=1;
                    }
                }
            }
        }
        return farthest;
    }
    void bfs2(int node, vector<int>&dis){
        queue<int>q;
        q.push(node);
        vector<int>visited(n);
        while(q.size()){
            for(int i=q.size();i>0;i--){
                int temp=q.front();
                q.pop();
                for(auto &it:dp[temp]){
                    if(!visited[it]){
                        dis[it]=max(dis[it], dis[temp]+1);
                        visited[it]=1;
                        q.push(it);
                    }
                }
            }
        }
    }
    string findSpecialNodes(int n, vector<vector<int>>& edges) {
        this->n=n;
        for(auto &it:edges){
            dp[it[0]].push_back(it[1]);
            dp[it[1]].push_back(it[0]);
        }
        int firstFarthestPoint = bfs1(0);
        int secondFarthestPoint = bfs1(firstFarthestPoint);
        vector<int>distanceA(n,0), distanceB(n,0);
        bfs2(firstFarthestPoint, distanceA);
        bfs2(secondFarthestPoint, distanceB);

        int diameter=*max_element(distanceA.begin(),distanceA.end());
        string result;
        for(int i=0;i<n;i++){
            result.push_back((diameter==max(distanceA[i],distanceB[i])?'1':'0'));
        }
        return result;
    }
};