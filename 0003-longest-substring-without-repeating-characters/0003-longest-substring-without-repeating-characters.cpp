class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int r = 0;
        int max_count = 0;
        unordered_map<int, int> map;
        while (r < n) {
            if (map.find(s[r]) != map.end()&& map[s[r]] >= l) {
                l = map[s[r]] + 1;
            }
            map[s[r]] = r;
            max_count = max(max_count, r - l + 1);
            r++;
        }
        return max_count;
    }
};