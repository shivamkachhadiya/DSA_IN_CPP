class Solution {
public:
    int largestInteger(int n, int s) {
        if (s == 0) return 0;  // <-- fix here
        if (s > 9 * n) return -1;

        string ans = "";
        for (int i = 0; i < n; i++) {
            int digit = min(9, s);
            ans.push_back('0' + digit);
            s -= digit;
        }
        return stoi(ans);
    }
};
