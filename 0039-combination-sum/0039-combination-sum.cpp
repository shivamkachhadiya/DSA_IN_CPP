class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& arr, int target, int i, int currSum, int n,vector<int>& part) {
        if (i >= n) {
            if (currSum == target) {
                ans.push_back(part);
                return;
            }
            return;
        }

        if(i>=n||currSum>target)return;

        if (currSum == target) {
            ans.push_back(part);
            return;
        }

        part.push_back(arr[i]);
        solve(arr, target, i, currSum + arr[i], n, part);
        part.pop_back();
        solve(arr, target, i + 1, currSum, n, part);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> part;
        solve(arr, target, 0, 0, n, part);
        return ans;
    }
};