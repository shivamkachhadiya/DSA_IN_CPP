class Solution {
public:
    // Previous smaller element index for each bar
    vector<int> leftSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> left_ans(n, -1);
        stack<int> st; // stores indices

        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            left_ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        return left_ans;
    }

    // Next smaller element index for each bar
    vector<int> rightSmaller(vector<int>& arr) {
        int n = arr.size();
        vector<int> right_ans(n, n);
        stack<int> st; // stores indices

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            right_ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        return right_ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        vector<int> left = leftSmaller(heights);
        vector<int> right = rightSmaller(heights);

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            maxi = max(maxi, heights[i] * width);
        }

        return maxi;
    }
};