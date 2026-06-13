class Solution {
public:
    // Recursive factorial (just for learning)
    int find_fact(int n) {
        if (n == 0 || n == 1) return 1;
        return n * find_fact(n - 1);
    }
    
    int trailingZeroes(int n) {
        // Trailing zeroes = count of prime factor 5 in n!
        // Formula: n/5 + n/25 + n/125 + ... [web:23][web:26]
        
        int count = 0;
        while (n >= 5) {
            n /= 5;
            count += n;
        }
        return count;
    }
};