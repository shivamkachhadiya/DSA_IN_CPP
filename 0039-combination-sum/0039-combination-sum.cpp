class Solution {
public:
    void solve(vector<int>& arr, int target, int n, vector<vector<int>>& ans,
               vector<int>& part, int i, int sum) {
        if (i == arr.size()) {
            if (sum == target) {
                ans.push_back(part);
            }
            return;
        }

        if (sum > target) {
            return;
        }
        if (sum == target) {
            ans.push_back(part);
            return;
        }

        part.push_back(arr[i]);
        solve(arr, target, n, ans, part, i, sum + arr[i]);
        part.pop_back();
        solve(arr, target, n, ans, part, i + 1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> ans;
        vector<int> part;
        solve(arr, target, n, ans, part, 0, 0);
        return ans;
    }
};