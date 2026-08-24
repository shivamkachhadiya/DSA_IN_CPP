class Solution {
public:
    int maxVowels(string s, int k) {
        auto isVowel = [](char c) {
            return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
        };

        int n = s.size();
        int count = 0;

        // Initial window
        for(int i=0; i<k; i++) {
            if(isVowel(s[i])) count++;
        }

        int maxCount = count;

        // Slide window
        for(int i=k; i<n; i++) {
            if(isVowel(s[i])) count++;
            if(isVowel(s[i-k])) count--;
            maxCount = max(maxCount, count);
        }

        return maxCount;
    }
};
