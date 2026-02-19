class Solution {
public:
    int calculate(string s) {
        long result = 0;
        long num = 0;
        int sign = 1;
        stack<int> st;

        for (char ch : s) {
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            } else if (ch == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (ch == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (ch == '(') {
                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (ch == ')') {
                result += sign * num;
                num = 0;

                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
            }
        }

        result += sign * num;
        return result;
    }
};