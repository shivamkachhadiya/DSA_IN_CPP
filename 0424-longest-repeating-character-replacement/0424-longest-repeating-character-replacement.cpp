class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        unordered_map<char, int> map;
        int left = 0;
        int maxFreq = 0;
        int maxLen = 0;

        for (int right = 0; right < n; right++) {
            map[s[right]]++;
            maxFreq = max(maxFreq, map[s[right]]);

            while ((right - left + 1) - maxFreq > k) {
                map[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};