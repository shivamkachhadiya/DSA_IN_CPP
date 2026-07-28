class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n = s.size();
        if (s == "")
            return 0;
        if (s == " ")
            return 1;
        if (n == 1)
            return 1;
        int l = 0;
        int r = 0;
        unordered_map<char, int> map;
        int max_len = 0;
        while (r < n) {
            if (map.find(s[r]) == map.end()) {
                map[s[r]] = r;
            } else {
                // mil gaya

                l = max(l, map[s[r]] + 1);
                map[s[r]] = r;
            }
            int len = r - l + 1;
            max_len = max(max_len, len);
            r++;
        }
        return max_len;
    }
};