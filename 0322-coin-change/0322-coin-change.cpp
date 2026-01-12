class Solution {
public:
    const int INF = 1e9;

    int solve(vector<int>& coins, int target, int i) {
        if (target == 0) return 0;

        if (i == 0) {
            if (target % coins[0] == 0)
                return target / coins[0];
            else
                return INF;
        }

        int notake = solve(coins, target, i - 1);
        int take = INF;

        if (coins[i] <= target)
            take = 1 + solve(coins, target - coins[i], i);

        return min(take, notake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = solve(coins, amount, n - 1);
        return (ans >= INF) ? -1 : ans;
    }
};
