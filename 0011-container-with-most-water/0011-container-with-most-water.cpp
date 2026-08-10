class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        int ans = 0;

        while (start < end) {
            int height = min(arr[start], arr[end]);
            int width = end - start;
            int area = height * width;
            ans = max(ans, area);

            if (arr[start] < arr[end]) {
                start++;
            } else {
                end--;
            }
        }
        return ans;
    }
};
