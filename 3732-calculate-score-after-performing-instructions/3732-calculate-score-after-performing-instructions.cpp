class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long ans=0;
        int n=instructions.size();
        vector<bool>visited(n);
        int index=0;
        while(index<n){
            if(index<0||index>=n||visited[index]) break;
            visited[index]=true;
            (instructions[index]=="jump")?index+=values[index]:(ans+=values[index],index++);
        }
        return ans;
    }
};