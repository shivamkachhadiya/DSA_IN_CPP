class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {}

    void push(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (!s1.empty()) {
            int val = s1.top();
            s1.pop();
            return val;
        }
        return -1; // or throw error
    }

    int peek() {
        if (!s1.empty()) {
            return s1.top();
        }
        return -1; // or throw error
    }

    bool empty() { return s1.empty(); }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */