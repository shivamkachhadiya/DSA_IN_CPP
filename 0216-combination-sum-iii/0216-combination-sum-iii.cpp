class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> currentCombination;
        backtrack(k, n, 1, currentCombination, result);
        return result;
    }

private:
    void backtrack(int k, int target, int start, vector<int>& combo, vector<vector<int>>& result) {
        if (combo.size() == k) {
            if (target == 0) {
                result.push_back(combo);
            }
            return;
        }

        for (int i = start; i <= 9; i++) {
            if (i > target) break;

            combo.push_back(i);
            backtrack(k, target - i, i + 1, combo, result);
            combo.pop_back(); 
        }
    }
};