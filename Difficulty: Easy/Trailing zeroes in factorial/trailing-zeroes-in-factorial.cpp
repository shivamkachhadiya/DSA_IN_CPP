class Solution {
public:
//zeros(n) = n/5 + n/25 + n/125 + ... (until n/power_of_5 == 0)

    int trailingZeroes(int n) {
        int count = 0;
        while (n > 0) {
            n /= 5;      // count multiples of 5, 25, 125, ...
            count += n;
        }
        return count;
    }
};
