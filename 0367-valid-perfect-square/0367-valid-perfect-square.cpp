#include <cmath> // for sqrt()

class Solution {
public:
    bool isPerfectSquare(int num) {
        int limit = (int)sqrt(num);
        for (int i = 1; i <= limit; i++) {
            if (i * i == num)
                return true;
        }
        return false;
    }
};
