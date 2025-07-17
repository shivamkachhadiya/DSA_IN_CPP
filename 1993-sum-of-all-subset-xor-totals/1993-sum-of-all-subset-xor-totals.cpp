class Solution {
public:
    int total = 0; // Final XOR sum of all subsets

    void solve(vector<int>& nums, int index, int xorValue) {
        if (index == nums.size()) {
            total += xorValue;
            return;
        }

        // Include nums[index] in XOR
        solve(nums, index + 1, xorValue ^ nums[index]);

        // Exclude nums[index] from XOR
        solve(nums, index + 1, xorValue);
    }

    int subsetXORSum(vector<int>& nums) {
        solve(nums, 0, 0);
        return total;
    }
};
