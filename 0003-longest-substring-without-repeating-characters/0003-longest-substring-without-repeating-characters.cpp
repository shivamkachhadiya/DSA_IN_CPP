class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int n = s.size();
        int left = 0;
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            map[s[i]]++;

            while (map[s[i]] > 1) {
                map[s[left]]--;
                if (map[s[i]] == 0)
                    map.erase(s[i]);

                left++;
            }

            count = max(count, i - left + 1);
        }
        return count;
    }
};