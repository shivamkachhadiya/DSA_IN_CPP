class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size())
            return "";
        unordered_map<char, int> freq;
        for (char c : t)
            freq[c]++;
        int count = t.size();
        int i = 0;
        int j = 0;
        int minLen = INT_MAX;
        int start = 0;
        while (j < s.size()) {
            if (freq[s[j]] > 0) {
                count--;
            }
            freq[s[j]]--;
            j++;

            while (count == 0) {
                if (j - i < minLen) {
                    minLen = j - i;
                    start = i;
                }
                freq[s[i]]++;
                if (freq[s[i]] > 0) {
                    count++;
                }
                i++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};