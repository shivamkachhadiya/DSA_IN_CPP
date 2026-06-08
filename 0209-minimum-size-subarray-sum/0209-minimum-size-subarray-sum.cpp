class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        queue<int> q;
        int sum = 0;
        int ans = INT_MAX;
        for (int x : nums) {
            q.push(x);
            sum += x;
            while (sum >= target) {
                ans = min(ans, (int)q.size());
                sum -= q.front();
                q.pop();
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};