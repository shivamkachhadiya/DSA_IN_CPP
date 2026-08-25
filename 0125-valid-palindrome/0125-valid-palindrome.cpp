class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (isalnum(s[i])) {
                temp.push_back(tolower(s[i]));
            }
        }
        int start = 0;
        int new_n = temp.size();
        int end = new_n - 1;
        while (start < end) {
            if (temp[start] != temp[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};