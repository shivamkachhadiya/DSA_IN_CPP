class Solution {
public:
    void solve(vector<int>& nums, int n, vector<int>& part,
               vector<vector<int>>& ans, int i) {
        if (i == n) {
            ans.push_back(part);
            return;
        }

        part.push_back(nums[i]);
        solve(nums, n, part, ans, i + 1);
        part.pop_back();
        solve(nums, n, part, ans, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> part;
        vector<vector<int>> ans;
        solve(nums, n, part, ans, 0);
        return ans;
    }
};