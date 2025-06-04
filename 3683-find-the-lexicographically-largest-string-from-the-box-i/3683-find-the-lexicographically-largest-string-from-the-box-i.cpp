class Solution {
public:
    string answerString(string word, int numFriends) {
        int n = word.size();
        if (numFriends == 1) {
            return word;
        }
        int largestStringSize = n - numFriends + 1;
        string result = "";
        for (int i = 0; i < n; i++) {
            result = max(result, word.substr(i, largestStringSize));
        }
        return result;
    }
};