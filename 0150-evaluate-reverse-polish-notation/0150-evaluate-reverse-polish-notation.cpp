class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" &&
                tokens[i] != "*") {
                int val = stoi(tokens[i]);
                st.push(val);
            }
            if (tokens[i] == "+") {
                int firstTop = st.top();
                st.pop();
                int secondTop = st.top();
                st.pop();
                st.push(firstTop + secondTop);
            } else if (tokens[i] == "-") {
                int firstTop = st.top();
                st.pop();
                int secondTop = st.top();
                st.pop();
                st.push(secondTop - firstTop);
            } else if (tokens[i] == "/") {
                int firstTop = st.top();
                st.pop();
                int secondTop = st.top();
                st.pop();
                if (secondTop != 0) {
                    st.push( secondTop/firstTop);
                } else
                    st.push(0);
            } else if (tokens[i] == "*") {
                int firstTop = st.top();
                st.pop();
                int secondTop = st.top();
                st.pop();
                st.push(firstTop * secondTop);
            }
        }
        return st.top();
    }
};