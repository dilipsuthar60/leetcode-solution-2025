class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string result = "";
        stack<char> st;
        if (pattern[0] == 'I') {
            result += '1';
        } else {
            st.push('1');
        }

        for (int i = 1; i <= n; i++) {
            if (pattern[i - 1] == 'I') {
                while (st.size()) {
                    result += st.top();
                    st.pop();
                }
            }
            st.push('0' + (i + 1));
        }
        while (st.size()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};