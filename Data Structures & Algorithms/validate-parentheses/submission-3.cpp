class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> pairs = {
            {')' , '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> st;

        for (char c : s) {
            if (pairs.count(c)) {
                if (st.empty() || st.top() != pairs[c]) {
                    return false;
                } else {
                    st.pop();
                }
            } else {
                st.push(c);
            }
        }
        return st.empty();
    }
};
