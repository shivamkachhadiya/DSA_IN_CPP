class Solution {
public:
    bool isVowel(char& s) {
        if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u') {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int temp = 0;

        int count = 0;
        int left = 0, right = 0;
        while (right < n) {
            int len = right - left + 1;
            if (len <= k) {
                if (isVowel(s[right])) {
                    temp++;
                }
                right++;
            } else {
                if (isVowel(s[left])) {
                    temp--;
                }
                left++;
            }
            count = max(count, temp);
        }
        return count;
    }
};