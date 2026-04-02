class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;
        int n = s.size();
        int i = 0, j = 0;
        int maxi = 1;
        int curr = 1;
        while (j < n) {
            if (freq.find(s[j]) == freq.end()) {
                freq[s[j]]++;
                j++;
                curr++;
                maxi = max(maxi, curr);
            } else {
                freq.erase(s[i]);
                i++;
                curr--;
            }
        }
        return maxi-1;
    }
};