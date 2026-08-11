class Solution {
public:
    bool isPalindrome(string s) {
        stack<char> st;
        string temp = "";
        for (char& x : s) {
            if (!isalnum(x))
                continue; // skip non-alphanumeric            
            temp.push_back(tolower(static_cast<unsigned char>(x)));
            st.push(tolower(static_cast<unsigned char>(x)));
        }

        int i = 0;
        int n = temp.size();
        while (i < n) {
             if (temp[i] != st.top()) {
                return false;  // mismatch found
            }
            if (temp[i] == st.top()) {
                st.pop();
                i++;
            }
        }
        return st.empty();
    }
};