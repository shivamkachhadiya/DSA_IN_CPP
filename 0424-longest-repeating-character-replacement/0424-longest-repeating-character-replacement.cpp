class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> map;
        int left = 0;
        int count = 0;
        int n = s.size();
        int maxF = 0;

        for (int right = 0; right < n; right++) {
            map[s[right] - 'A']++;
            maxF = max(maxF, map[s[right] - 'A']);

            while ((right-left+1)-maxF>k) {
                map[s[left] - 'A']--;
                left++;
            }

            count = max(count, right - left + 1);
        }
        return count;
    }
};