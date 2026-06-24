class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> s;
        for (int i = 0; i < n; i++) {
            if (tokens[i] != "+" && tokens[i] != "*" && tokens[i] != "-" &&
                tokens[i] != "/") {
                int val = stoi(tokens[i]);
                s.push(val);
            } else {
                int right = s.top();
                s.pop();
                int left = s.top();
                s.pop();
                if (tokens[i] == "+") {
                    s.push(right + left);
                } else if (tokens[i] == "-") {
                    s.push(left - right);
                } else if (tokens[i] == "*")
                    s.push(left * right);
                else {
                    s.push(left / right);
                }
            }
        }
        return s.top();
    }
};