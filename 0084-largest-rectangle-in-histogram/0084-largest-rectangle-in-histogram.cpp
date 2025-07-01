class Solution {
public:
    vector<int> nextSmallerToLeft(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        stack<int> s;
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            left[i] = s.empty() ? -1 : s.top();
            s.push(i);
        }
        return left;
    }

    vector<int> nextSmallerToRight(vector<int>& arr) {
        int n = arr.size();
        vector<int> right(n);
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            right[i] =
                s.empty()
                    ? n
                    : s.top(); // IMPORTANT: return n if no smaller element
            s.push(i);
        }
        return right;
    }

    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int> left = nextSmallerToLeft(arr);
        vector<int> right = nextSmallerToRight(arr);

        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int area = arr[i] * width;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};
