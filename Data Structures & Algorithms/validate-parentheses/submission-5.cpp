class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> brackets = {
            {')', '('},
            {'}', '{'},
            {']', '['},
        };
        for (char c: s) {
            if (brackets.find(c) == brackets.end()) {
                st.push(c);
            }
            else {
                if (!st.empty()) {
                    if (brackets[c] != st.top()) return false;
                    else st.pop();
                }
                else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};
