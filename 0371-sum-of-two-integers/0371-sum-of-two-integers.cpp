class Solution {
public:
    int getSum(int a, int b) {
        // Loop until there is no carry left to add
        while (b != 0) {
            
            // Step 1: Calculate the carry
            // a & b gives the positions where both a and b have 1s (i.e., carry bits)
            // Shift left by 1 to move the carry to the correct position for the next addition
            unsigned carry = (unsigned)(a & b) << 1;

            // Step 2: Add without carrying
            // a ^ b gives the sum of a and b where no carry is involved
            a = a ^ b;

            // Step 3: Assign carry to b
            // b now holds the carry which needs to be added in the next iteration
            b = carry;
        }

        // When carry becomes 0, 'a' holds the final result
        return a;
    }
};
