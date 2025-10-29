class Solution {
public:
    int smallestNumber(int n) {
        int bit;
        int count = 0;
        while (n != 0) {
            bit = n % 2;

            n = n / 2;
            count++;
        }
        
        int ans = pow(2, count); // 2^3 = 8
        return ans - 1;
    }
    
};