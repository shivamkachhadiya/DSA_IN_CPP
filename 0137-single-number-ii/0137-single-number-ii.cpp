class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int x : nums) {
            ones = (ones ^ x) & ~twos; // ek baar count
            twos = (twos ^ x) & ~ones; // do baar count
        }
        return ones; // jo 3 se repeat nahi hua
    }
};
