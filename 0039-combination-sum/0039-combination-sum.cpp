class Solution {
public:
    void solve(vector<int>& arr, int target, int n, vector<vector<int>>& ans,
               vector<int>& part, int curr_sum, int i) {
        if (i >= n) {
            if (curr_sum == target) {
                ans.push_back(part);
                return;
            }
            return;
        }
        if (curr_sum == target) {
            ans.push_back(part);
            return;
        }
        if (curr_sum > target) {
            return;
        }
        part.push_back(arr[i]);
        solve(arr, target, n, ans, part, curr_sum + arr[i], i);
        part.pop_back();
        solve(arr, target, n, ans, part, curr_sum, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> ans;
        vector<int> part;
        solve(arr, target, n, ans, part, 0, 0);
        return ans;
    }
};