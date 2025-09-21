class Solution {
public:
    vector<int> solve(vector<int>& nums, int prev_index, int curr_index) {
        if (curr_index == nums.size()) {
            return {};
        }

        // Choice 1: Take nums[curr_index] if divisible
        vector<int> take;
        if (prev_index == -1 || nums[curr_index] % nums[prev_index] == 0) {
            // next call mei jo abhi current index hei vo previous index ban
            // jayega and jo curr index hei v +1 hoke aage badh jayega
            take = solve(nums, curr_index, curr_index + 1);

            take.insert(take.begin(), nums[curr_index]);
        }

        // Choice 2: Skip nums[curr_index]
        vector<int> notTake = solve(nums, prev_index, curr_index + 1);

        // Return the bigger subset
        return (take.size() > notTake.size()) ? take : notTake;
    }

    vector<int> solveMEM(vector<int>& nums, int prev_index, int curr_index,
                         vector<vector<vector<int>>>& dp) {
        if (curr_index == nums.size()) {
            return {};
        }
        if (!dp[prev_index + 1][curr_index].empty()) {
            return dp[prev_index + 1][curr_index];
        }

        // Choice 1: Take nums[curr_index] if divisible
        vector<int> take;
        if (prev_index == -1 || nums[curr_index] % nums[prev_index] == 0) {
            // next call mei jo abhi current index hei vo previous index ban
            // jayega and jo curr index hei v +1 hoke aage badh jayega
            take = solveMEM(nums, curr_index, curr_index + 1, dp);

            take.insert(take.begin(), nums[curr_index]);
        }

        // Choice 2: Skip nums[curr_index]
        vector<int> notTake = solveMEM(nums, prev_index, curr_index + 1, dp);

        // Store and return best
        if (take.size() > notTake.size()) {
            return dp[prev_index + 1][curr_index] = take;
        }
        return dp[prev_index + 1][curr_index] = notTake;
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // important step!
        int n = nums.size();           
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n));

        // return solve(nums, -1, 0);

        return solveMEM(nums, -1, 0, dp);
    }
};