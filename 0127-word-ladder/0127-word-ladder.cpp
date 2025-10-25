class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(beginWord==endWord) return 0;
        unordered_map<string,int>distance;
        for(auto &word: wordList){
            distance[word]=1e8;
        }
        queue<string>q;
        q.push(beginWord);
        distance[beginWord]=1;
        while(q.size()){
            auto currentWord=q.front();
            q.pop();
            if(currentWord==endWord){
                break;
            }
            for(int i=0;i<currentWord.size();i++){
                string newWord=currentWord;
                for(char ch='a';ch<='z';ch++){
                    newWord[i]=ch;
                    if(newWord!=currentWord&&distance.count(newWord)&&distance[newWord]>distance[currentWord]+1){
                        distance[newWord]=distance[currentWord]+1;
                        q.push(newWord);
                    }
                }
            }
        }
        return distance[endWord]==1e8?0:distance[endWord];
    }
};