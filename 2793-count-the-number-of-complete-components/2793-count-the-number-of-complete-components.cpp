class Solution {
public:
    vector<int>graph[60];
    void find(int node, vector<bool>&visited,int &countNode, int &countEdges){
        visited[node]=1;
        countNode++;
        countEdges+=graph[node].size();
        for(auto &child:graph[node]){
            if(!visited[child]){
                find(child,visited, countNode,countEdges);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(auto &edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        vector<bool>visited(n+1);
        int countNode=0,countEdges=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                countNode=0,countEdges=0;
                find(i, visited, countNode, countEdges);
                ans+=(countEdges==(countNode*(countNode-1)));
            }
        }
        return ans;
    }
};