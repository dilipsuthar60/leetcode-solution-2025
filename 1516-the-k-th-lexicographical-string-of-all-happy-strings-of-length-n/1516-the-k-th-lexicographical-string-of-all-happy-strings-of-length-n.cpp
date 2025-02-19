class Solution {
public:
    string getHappyString(int n, int k) {
        queue<string> q;
        q.push("a");
        q.push("b");
        q.push("c");
        vector<string> v;
        while (q.size()) {
            auto temp = q.front();
            q.pop();
            if (temp.size() > n) {
                break;
            }
            if (temp.size() == n) {
                v.push_back(temp);
            }
            for (char i = 'a'; i <= 'c'; i++) {
                if (temp[temp.size() - 1] != i) {
                    q.push(temp + i);
                }
            }
        }

        if (v.size() >= k) {
            return v[k - 1];
        }
        return "";
    }
};