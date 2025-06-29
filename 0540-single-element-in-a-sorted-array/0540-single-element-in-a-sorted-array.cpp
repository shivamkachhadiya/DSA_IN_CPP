class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return arr[0];

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                if (arr[i] != arr[i + 1])
                    return arr[i];
            } else if (i == n - 1) {
                if (arr[i] != arr[i - 1])
                    return arr[i];
            } else {
                if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
                    return arr[i];
            }
        }

        return -1; // Should never reach here if input is valid
    }
};
