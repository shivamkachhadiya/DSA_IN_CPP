class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getPerms(nums, 0, ans);
        return ans;
    }

private:
    void getPerms(vector<int>& nums, int idx, vector<vector<int>>& ans) {
        // Base Case: If the index reaches the end, store the permutation
        if (idx == nums.size()) {
            ans.push_back(nums);
            return;
        }

        for (int i = idx; i < nums.size(); ++i) {
            // Swap to fix ith element at current index
            swap(nums[idx], nums[i]);

            // Recursive call with next index
            getPerms(nums, idx + 1, ans);

            // Backtrack (undo the swap)
            swap(nums[idx], nums[i]);
        }
    }
};
