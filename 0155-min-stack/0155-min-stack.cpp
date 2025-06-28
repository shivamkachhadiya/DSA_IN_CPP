class MinStack {
    stack<int> s;
    stack<int> minS;

public:
    void push(int val) {
        s.push(val);
        if (minS.empty() || val <= minS.top()) {
            minS.push(val);
        } else {
            minS.push(minS.top());
        }
    }

    void pop() {
        s.pop();
        minS.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return minS.top();
    }
};
