class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

    unordered_map<char, char> mapST;
    unordered_set<char> mappedValues;

    for (int i = 0; i < s.length(); ++i) {
        char c1 = s[i];
        char c2 = t[i];

        if (mapST.count(c1)) {
            if (mapST[c1] != c2) return false;  // Mismatch
        } else {
            if (mappedValues.count(c2)) return false;  // Already mapped by some other char
            mapST[c1] = c2;
            mappedValues.insert(c2);
        }
    }

    return true;
    }
};