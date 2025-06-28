#include <queue>
using namespace std;

class MyStack {
    queue<int> q; // only one queue used to simulate stack

public:
    MyStack() {
        // Constructor – nothing to initialize since we use STL queue
    }

    // Push operation: O(n) time
    void push(int x) {
        int s = q.size(); // get current queue size
        q.push(x);        // insert new element at back

        // Rotate all old elements behind the new one
        for (int i = 0; i < s; i++) {
            q.push(q.front());
            q.pop();
        }

        // Now x is at the front of the queue = top of stack
    }

    // Pop operation: O(1) time
    int pop() {
        // Front of queue = top of stack
        int val = q.front();
        q.pop();
        return val;
    }

    // Top operation: O(1) time
    int top() {
        return q.front(); // return the front of the queue
    }

    // Empty operation: O(1) time
    bool empty() {
        return q.empty(); // check if queue is empty
    }
};
