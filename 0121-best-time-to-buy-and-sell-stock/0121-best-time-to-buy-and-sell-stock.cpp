class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int bestBuy = prices[0], global_profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            global_profit = max(global_profit, prices[i] - bestBuy);
            bestBuy = min(bestBuy, prices[i]);
        }
        return global_profit;
    }
};
