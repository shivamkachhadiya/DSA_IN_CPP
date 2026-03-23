class Solution {
private:
    bool possible(vector<int>& arr, int n, int m, int mid) {
        int student = 1;
        int page = 0;
        for (int i = 0; i < n; i++) {

            if (page + arr[i] <= mid) {
                page += arr[i];
            } else {
                
                student++;
                if (student > m || arr[i] > mid) {
                    return false;
                }
                page = 0;
                page += arr[i];
            }
        }

        return true;
    }

public:
    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        int s = 0, sum = 0;
        for (auto i : arr) {
            sum += i;
        }
        int e = sum;
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (possible(arr, n, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};