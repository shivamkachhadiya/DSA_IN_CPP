class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // Optimization: Pigeonhole Principle.
        // We only have 10 unique digits (0-9). 
        // Any number with length > 10 must have duplicates.
        if (n > 10) {
            return countNumbersWithUniqueDigits(10);
        }

        // Base Case: For n=0, the range is 0 <= x < 1. 
        // The only number is 0.
        if (n == 0) {
            return 1;
        }

        // Step 1: Calculate unique numbers of length EXACTLY n
        // Start with 9 choices for the first digit (1-9)
        int uniquenumbers_len_n = 9;
        int available_digits = 9;

        // Multiply for the remaining positions (n-1 positions)
        // Example for n=3: 9 * 9 * 8
        for (int i = 0; i < n - 1; i++) {
            uniquenumbers_len_n *= available_digits;
            available_digits--;
        }

        // Step 2: Recursive call for n-1 and add current length count
        return countNumbersWithUniqueDigits(n - 1) + uniquenumbers_len_n;
    }
};