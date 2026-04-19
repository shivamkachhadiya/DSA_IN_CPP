class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end()); // MISTAKE: array must be sorted first

        int n = arr.size();
        vector<vector<int>>
            result; // MISTAKE 1: Fixed variable name from "ans" to "result"
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && arr[i] == arr[i - 1])
                continue; // MISTAKE 2: Changed i==0 to i>0 (avoid i-1=-1) int
                          // left = i + 1;
            int left = i + 1;

            int right = n - 1;
            int sum = -1 * arr[i];
            while (left < right) {
                int s = arr[left] + arr[right];
                if (s == sum) {
                    // MISTAKE 3: Fixed push_back() left++;
                    result.push_back({arr[i], arr[left], arr[right]});
                    left++;
                    right--;
                    while (left < right && arr[left] == arr[left - 1]) {
                        left++;
                    }
                    while (right > left && arr[right] == arr[right + 1]) {
                        right--;
                    }
                } else if (s < sum) {
                    left++;
                } else {
                    right--;
                }
            }
        }
        return result;
    }
};