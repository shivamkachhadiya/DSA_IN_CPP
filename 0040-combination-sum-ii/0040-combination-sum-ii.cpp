class Solution {
public:
    void solve(vector<int>& arr, int target, vector<int>& part,
               vector<vector<int>>& ans, int i, int sum) {
        if (i == arr.size()) {
            if (target == sum) {
                ans.push_back(part);
            }
            return;
        }
        if (sum == target) {
            ans.push_back(part);
            return;
        }
        if (sum > target)
            return;
        part.push_back(arr[i]);
        solve(arr, target, part, ans, i + 1, sum + arr[i]);
        part.pop_back();

        // Skip duplicates when not including
        int j = i + 1;
        while (j < arr.size() && arr[j] == arr[i]) {
            j++;
        }
        solve(arr, target, part, ans, j, sum);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        vector<int> part;
        vector<vector<int>> ans;
        solve(candidates, target, part, ans, 0, 0);
        return ans;
    }
};
