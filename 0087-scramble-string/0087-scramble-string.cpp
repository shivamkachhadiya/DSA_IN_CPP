class Solution {
public:
    unordered_map<string, bool> memo;

    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
        string key = s1 + "_" + s2;
        if (memo.count(key)) return memo[key];

        int n = s1.length();
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return memo[key] = false;
        }

        for (int i = 1; i < n; i++) {
            bool noSwap = isScramble(s1.substr(0, i), s2.substr(0, i)) && 
                          isScramble(s1.substr(i), s2.substr(i));
            if (noSwap) return memo[key] = true;

            bool withSwap = isScramble(s1.substr(0, i), s2.substr(n - i)) && 
                            isScramble(s1.substr(i), s2.substr(0, n - i));
            if (withSwap) return memo[key] = true;
        }

        return memo[key] = false;
    }
};