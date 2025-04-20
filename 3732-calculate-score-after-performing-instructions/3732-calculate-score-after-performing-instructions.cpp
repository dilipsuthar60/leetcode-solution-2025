class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long ans=0;
        int n=instructions.size();
        vector<bool>visited(n);
        for(int i=0;i<n;){
            if(i<0||i>=n||visited[i]) break;
            visited[i]=true;
            if(instructions[i]=="jump"){
                i+=(values[i]);
            }
            else{
                ans+=values[i];
                i++;
            }
        }
        return ans;
    }
};