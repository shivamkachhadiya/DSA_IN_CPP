class Solution {
public:
    int min = INT_MAX;
    int max = INT_MIN;
    // long long solve(string& s, int n, int i, long long ans, int sign) {
    //     if (i > n || !s[i]) {
    //         return (int)sign * ans;
    //     }
    //     if (sign * ans <= min) {
    //         return min;
    //     }
    //     if (sign * ans >= max) {
    //         return max;
    //     }
    //     return solve(s,n,i+1,ans,sign);
    // }
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long ans = 0;
        int sign = 1;

        while (i < n && s[i] == ' ')
            i++;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        while (i < n && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');
            if (sign == 1 && ans >= INT_MAX)
                return INT_MAX;
            if (sign == -1 && -ans <= INT_MIN)
                return INT_MIN;
            i++;
        }

        return (int)(sign * ans);

        // int n = s.size();
        // for (int i = 0; i < n; i++) {
        //     while (i < n && s[i] == ' ') {
        //         i++;
        //     }
        //     int sign = 1;
        //     while (i < n && (s[i] == '+' || s[i] == '-')) {
        //         sign = (s[i] == '-') ? -1 : 1;
        //         i++;
        //     }
        //     long long ans = solve(s, n, i, 0, sign);
        // }
        // return abs(ans);
    }
};