class Solution {
public:
    /**
     * Counts the number of operations needed until one number becomes zero.
     * In each operation, subtract the smaller number from the larger number.
     * 
     * @param num1 First positive integer
     * @param num2 Second positive integer
     * @return Number of operations performed
     */
    int countOperations(int num1, int num2) {
        int operationCount = 0;
      
        // Continue operations while both numbers are non-zero
        while (num1 != 0 && num2 != 0) {
            // Subtract the smaller number from the larger number
            if (num1 >= num2) {
                num1 -= num2;
            } else {
                num2 -= num1;
            }
          
            // Increment the operation counter
            operationCount++;
        }
      
        return operationCount;
    }
};