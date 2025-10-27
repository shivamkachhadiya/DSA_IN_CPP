class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = countOnes(bank[0]);
        int res = 0;

        for (int i = 1; i < bank.size(); i++) {
            int curr = countOnes(bank[i]);
            if (curr > 0) {
                res += prev * curr;
                prev = curr;
            }
        }

        return res;
    }

private:
    int countOnes(const string& s) {
        return count(s.begin(), s.end(), '1');
    }
};