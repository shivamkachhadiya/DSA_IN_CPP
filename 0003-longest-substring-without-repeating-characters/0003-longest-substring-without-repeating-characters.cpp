class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int>mapp;
        int left = 0, right = 0, maxLen = 0;
        while (right < n) {
            if (mapp.find(s[right]) == mapp.end()|| mapp[s[right]] < left) {
                mapp[s[right]] = right;
                maxLen = max(maxLen, right - left + 1);
                right++;
            } else {
                left = mapp[s[right]] + 1;
                mapp[s[right]]=right;
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
        }
        return maxLen;
    }
};