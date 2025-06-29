class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor_all = 0;
        int xor_arr = 0;
        int n = nums.size();

        // XOR all numbers from 0 to n
        for (int i = 0; i <= n; i++) {
            xor_all ^= i;
        }

        // XOR all elements in nums
        for (int i = 0; i < n; i++) {
            xor_arr ^= nums[i];
        }

        // XOR of xor_all and xor_arr gives the missing number
        return xor_all ^ xor_arr;
    }
};
