class Solution {
public:
    int nextBeautifulNumber(int n) {
        // Iterate through numbers starting from n + 1 until we find a beautiful number
        for (int candidate = n + 1;; ++candidate) {
            // Count frequency of each digit (0-9) in the current number
            int digitFrequency[10] = {0};
          
            // Extract each digit and count its frequency
            for (int temp = candidate; temp > 0; temp /= 10) {
                int digit = temp % 10;
                ++digitFrequency[digit];
            }
          
            // Check if the current number is beautiful
            // A beautiful number has each digit appearing exactly as many times as its value
            bool isBeautiful = true;
          
            // Verify each digit appears exactly as many times as its value
            for (int temp = candidate; temp > 0; temp /= 10) {
                int digit = temp % 10;
              
                // If digit doesn't appear exactly 'digit' times, it's not beautiful
                if (digit != digitFrequency[digit]) {
                    isBeautiful = false;
                    break;
                }
            }
          
            // Return the first beautiful number found
            if (isBeautiful) {
                return candidate;
            }
        }
    }
};