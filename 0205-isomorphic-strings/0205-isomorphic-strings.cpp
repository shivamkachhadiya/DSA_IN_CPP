class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        unordered_map<char, int> m1, m2;

        for (int i = 0; i < s.length(); ++i) {
            // Store the first occurrence index of each character if not already stored
            if (m1.find(s[i]) == m1.end()) m1[s[i]] = i;
            if (m2.find(t[i]) == m2.end()) m2[t[i]] = i;

            // If the pattern (index of first occurrence) doesn't match
            if (m1[s[i]] != m2[t[i]]) return false;
        }
        return true;
    }
};
