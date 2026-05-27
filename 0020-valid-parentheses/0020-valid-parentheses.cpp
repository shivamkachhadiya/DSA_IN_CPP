class Solution {
public:
    bool isValid(string s) {
        stack<int> st;

        for (auto ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                st.push(ch);
            }

            else {
                if (st.empty())
                    return false;
                char stchar = st.top();
                if (ch == ']' && stchar != '[' || ch == '}' && stchar != '{' ||
                    ch == ')' && stchar != '(') {
                    return false;
                }
                st.pop();

            }
        }
        return st.empty();
    }
};