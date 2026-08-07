class Solution {
public:
    long long gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
    long long ans = 1;
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long first = nums[i];
                long long second = nums[j];
                long long multi = first * second;

                long long div = gcd(first, second) * gcd(first, second);
                long long tempAns = multi / div;
                ans = max(ans, tempAns);
            }
        }
        return ans;
    }
};