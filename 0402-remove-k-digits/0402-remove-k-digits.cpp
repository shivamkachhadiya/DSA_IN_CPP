class Solution {
public:
    string removeKdigits(string arr, int k) {
        stack<char> s;

        for (char digit : arr) {
            while (!s.empty() && k > 0 && s.top() > digit) {
                s.pop();
                k--;
            }
            if (!s.empty() || digit != '0')  // avoid leading zeros
                s.push(digit);
        }

        // remove extra digits if k still > 0
        while (!s.empty() && k--) s.pop();

        // build the result string
        string result = "";
        while (!s.empty()) {
            result += s.top();
            s.pop();
        }
        reverse(result.begin(), result.end());

        return result.empty() ? "0" : result;
    }
};
