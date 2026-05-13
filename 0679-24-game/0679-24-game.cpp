class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return dfs(nums);
    }
    
private:
    bool dfs(vector<double>& nums) {
        int n = nums.size();
        if (n == 1) {
            return abs(nums[0] - 24.0) < 1e-6;
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                double a = nums[i], b = nums[j];
                vector<double> next;
                for (int k = 0; k < n; ++k) {
                    if (k != i && k != j) next.push_back(nums[k]);
                }
                
                vector<double> results;
                results.push_back(a + b);
                results.push_back(a - b);
                results.push_back(b - a);
                results.push_back(a * b);
                if (abs(b) > 1e-6) results.push_back(a / b);
                if (abs(a) > 1e-6) results.push_back(b / a);
                
                for (double val : results) {
                    next.push_back(val);
                    if (dfs(next)) return true;
                    next.pop_back();
                }
            }
        }
        return false;
    }
};