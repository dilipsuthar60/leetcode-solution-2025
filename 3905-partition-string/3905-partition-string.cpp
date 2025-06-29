class Solution {
public:
    vector<string> partitionString(string s) {
        int n=s.size();
        vector<string>ans;
        unordered_set<string>visited;
        string currentSegment="";
        for(int i=0;i<n;i++){
            currentSegment+=s[i];
            if(visited.find(currentSegment)==visited.end()){
                ans.push_back(currentSegment);
                visited.insert(currentSegment);
                currentSegment="";
            }
        }
        return ans;
    }
};