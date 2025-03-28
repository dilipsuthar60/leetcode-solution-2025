class Solution {
public:
    vector<int>graph[101];
    void dfs(int node,vector<bool>&visited){
        visited[node]=true;
        for(auto &child:graph[node]){
            if(!visited[child]){
                dfs(child, visited);
            }
        }
    }
    int intersectionCount(vector<int>&list1,vector<int>&list2){
        unordered_set<int>set1(list1.begin(),list1.end());
        int count=0;
        for(auto &element:list2){
            if(set1.find(element)!=set1.end()){
                count++;
                set1.erase(element);
            }
        }
        return count;
    }
    int numberOfComponents(vector<vector<int>>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if((intersectionCount(nums[i],nums[j])>=k)&&i!=j){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        int counter=0;
        vector<bool>visited(103);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited);
                counter++;
            }
        }
        return counter;
    }
};