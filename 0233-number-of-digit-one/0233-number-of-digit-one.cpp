class Solution {
public:
    int countDigitOne(int n) {
        if (n <= 0) return 0;
        
        long long count = 0;
        for (long long i = 1; i <= n; i *= 10) {
            long long divider = i * 10;
            
            // Full sets of 10^k sequences
            count += (n / divider) * i;
            
            // Remaining part of the sequence
            long long currentDigit = (n / i) % 10;
            if (currentDigit == 1) {
                count += (n % i) + 1;
            } else if (currentDigit > 1) {
                count += i;
            }
        }
        
        return (int)count;
    }
};