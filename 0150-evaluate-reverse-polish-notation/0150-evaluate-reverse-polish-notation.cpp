
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (string& token : tokens) {
            // If token is an operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top(); st.pop();  // second operand
                int a = st.top(); st.pop();  // first operand
                
                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else if (token == "/") st.push(a / b);  // truncates toward zero
            }
            else {
                // Token is a number
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};