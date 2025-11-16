class Solution {
public:
    int numSub(string s) {
        // Constants
        const int MOD = 1000000007;  // 10^9 + 7 for modulo operation
      
        // Variables to track the result and current consecutive ones
        int totalCount = 0;           // Total number of valid substrings
        int consecutiveOnes = 0;      // Current length of consecutive '1's
      
        // Iterate through each character in the string
        for (const char& currentChar : s) {
            if (currentChar == '1') {
                // If current character is '1', increment the consecutive count
                consecutiveOnes++;
                // Add the number of new substrings ending at current position
                totalCount = (totalCount + consecutiveOnes) % MOD;
            } else {
                // If current character is '0', reset the consecutive count
                consecutiveOnes = 0;
            }
        }
      
        return totalCount;
    }
};
