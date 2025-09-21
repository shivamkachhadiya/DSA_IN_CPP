class Solution {
public:
    vector<vector<pair<int,int>>> dp; 
    // dp[prev+1][curr] = {length, count}

    pair<int,int> solve(vector<int>& nums, int prev, int curr) {
        if (curr == nums.size()) {
            return {0, 1}; // length=0, count=1 (1 way: take nothing)
        }

        if (dp[prev+1][curr].first != -1) {
            return dp[prev+1][curr];
        }

        // Option 1: Skip current
        auto skip = solve(nums, prev, curr+1);

        // Option 2: Take current (if valid)
        pair<int,int> take = {0,0};
        if (prev == -1 || nums[curr] > nums[prev]) {
            auto next = solve(nums, curr, curr+1);
            take.first = 1 + next.first;
            take.second = next.second;
        }

        // Now merge results
        pair<int,int> ans;
        if (take.first > skip.first) {
            ans = take;
        } 
        else if (take.first < skip.first) {
            ans = skip;
        } 
        else { 
            // same length → add counts
            ans.first = take.first;
            ans.second = take.second + skip.second;
        }

        return dp[prev+1][curr] = ans;
    }

    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n+1, vector<pair<int,int>>(n, {-1,-1}));

        auto res = solve(nums, -1, 0);
        return res.second; // total number of LIS
    }
};
