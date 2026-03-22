class Solution {
public:
    int minPartitions(string n) {
        char maxDigit = '0';
        
        for (char c : n) {
            if (c > maxDigit) {
                maxDigit = c;
            }
            if (maxDigit == '9') break;
        }
        
        return maxDigit - '0';
    }
};