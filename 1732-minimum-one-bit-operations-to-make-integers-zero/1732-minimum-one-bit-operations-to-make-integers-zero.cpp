class Solution {
public:
    int minimumOneBitOperations(int n) {
        // Initialize the result variable to store the Gray code inverse
        int result = 0;
      
        // Process each bit of n from right to left
        // This implements the inverse Gray code formula
        while (n > 0) {
            // XOR the current result with n
            // This accumulates the XOR of all right-shifted versions of n
            result ^= n;
          
            // Right shift n by 1 bit for the next iteration
            n >>= 1;
        }
      
        // Return the final result which represents the minimum operations
        return result;
    }
};