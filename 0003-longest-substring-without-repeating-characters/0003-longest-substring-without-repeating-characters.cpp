class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int left = 0, right = 0;
        int n = s.size();
        int maxLength = 0;
        
        while (right < n) {
            if (map.find(s[right]) == map.end()) {
                map[s[right]] = right;
                right++;
            } else {
                left = max(left, map[s[right]] + 1);
                map[s[right]] = right;
                right++;
            }
            int currentLength = right - left;
            maxLength = max(currentLength, maxLength);
        }
        return maxLength;
    }
};