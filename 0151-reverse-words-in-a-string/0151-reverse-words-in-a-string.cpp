class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string ans = "";

        reverse(s.begin(), s.end());
        // eulb si yks eth
        // n=15
        for (int i = 0; i < n; i++) {
            string word = "";
            while (i < n && s[i] != ' ') {
                word = word + s[i];
                i++;
            }
            reverse(word.begin(), word.end());
            if (word.length() > 0) {
                ans = ans + " " + word;
            }
        }
        return ans.substr(1);
    }
};