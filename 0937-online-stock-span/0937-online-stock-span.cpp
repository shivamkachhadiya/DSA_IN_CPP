class StockSpanner {
public:
    stack<pair<int, int>> s; // pair => {price, span}

    StockSpanner() {
        // No initialization needed beyond this
    }

    int next(int price) {
        int span = 1;

        // Jab tak stack empty nahi hai aur top ka price <= current price
        while (!s.empty() && s.top().first <= price) {
            span += s.top().second; // Add uska span
            s.pop(); // Remove us price ko
        }

        s.push({price, span}); // Store current price with its span
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */