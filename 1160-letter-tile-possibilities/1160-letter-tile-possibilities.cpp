class Solution {
public:
    unordered_set<string> unique;
    void find(string& s, int index, string& currentAnswer,
              vector<bool>& visited) {
        unique.insert(currentAnswer);
        for (int i = 0; i < s.size(); i++) {
            if (visited[i]) {
                continue;
            }
            visited[i] = true;
            currentAnswer.push_back(s[i]);
            find(s, index + 1, currentAnswer, visited);
            visited[i] = false;
            currentAnswer.pop_back();
        }
    }
    int numTilePossibilities(string tiles) {
        vector<bool> visited(tiles.size());
        string currentAnswer = "";
        find(tiles, 0, currentAnswer, visited);
        return unique.size() - 1;
    }
};