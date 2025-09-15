class Solution {
public:
    int find(string &s, vector<bool>&visited){
        for(auto &it:s){
            if(visited[it-'a']) return false;
        }
        return true;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        istringstream ss(text);
        string current="";
        int count=0;

        vector<bool>visited(26);
        for(auto &it: brokenLetters) visited[it-'a']=true;

        while(ss>>current){
            count+=find(current, visited);
        }
        return count;
    }
};