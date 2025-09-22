class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            int prev = arr[i] - difference;
            
            // length of subsequence ending at arr[i]
            int currLen = 1;
            if (dp.count(prev)) {
                currLen = dp[prev] + 1;
            }

            dp[arr[i]] = currLen;
            ans = max(ans, currLen);
        }
        return ans;
    }
};
