class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0;
        int maxlen = 0;
        unordered_map<char, int> map;
        while (r < n) {
            char c = s[r];
            if (map.find(c) != map.end()) {
                l = max(l, map[c] + 1);
            }
            map[c] = r;
            maxlen = max(maxlen, r - l + 1);
            r++;
        }
        return maxlen;
    }
};