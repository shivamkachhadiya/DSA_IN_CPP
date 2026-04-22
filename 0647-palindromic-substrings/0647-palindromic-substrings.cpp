class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;

        for (int i = 0; i < s.size(); i++) {
            for (int j = i; j < s.size(); j++) {
                int l = i, r = j;
                while (l < r && s[l] == s[r]) {
                    l++;
                    r--;
                }
                res += (l >= r);
            }
        }

        return res;
    }
};