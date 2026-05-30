class Solution {
public:
    int addDigits(int num) {
        // direct formula use karo (digital root)
        if(num == 0) return 0;
        return 1 + (num - 1) % 9;
    }
};
