class Solution {
public:
    void solve(int i, int k, int target, vector<int>& part,
               vector<vector<int>>& ans, int sum) {

        if (sum == target && part.size() == k) {
            ans.push_back(part);
            return;
        }
        if (sum > target || part.size() > k || i > 9)
            return;

        part.push_back(i);
        solve(i + 1, k, target, part, ans, sum + i);
        part.pop_back();
        solve(i + 1, k, target, part, ans, sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> part;

        solve(1, k, n, part, ans, 0);

        return ans;
    }
};