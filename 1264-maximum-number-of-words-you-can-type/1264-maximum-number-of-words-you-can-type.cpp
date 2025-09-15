class Solution {
public:
    int find(string &s, string &p){
        vector<bool>visited(26);
        for(auto &it:p) visited[it-'a']=true;
        for(auto &it:s){
            if(visited[it-'a']) return false;
        }
        return true;
    }
    int canBeTypedWords(string text, string brokenLetters) {
        istringstream ss(text);
        string current="";
        int count=0;
        while(ss>>current){
            count+=find(current, brokenLetters);
        }
        return count;
    }
};