class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int start = 0;
        int end = n - 1;
        for (char& c : s) {
            c = std::tolower(c);
        }
        while (start < end) {
            if (!iswalnum(s[start])) {// check is alphanumeric or not iswalnum()
                start++;
                continue;
            }
            if (!iswalnum(s[end])) {
                end--;
                continue;
            }
            if (s[start] != s[end]) {
                return false;

            } else {
                start++;
                end--;
            }
        }
        return true;
    }
};