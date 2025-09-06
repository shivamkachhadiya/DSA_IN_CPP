class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ops;
        int idx = 0;
        for (int num = 1; num <= n && idx < target.size(); num++) {
            if (num == target[idx]) {
                ops.push_back("Push");
                idx++;
            } else {
                ops.push_back("Push");
                ops.push_back("Pop");
            }
        }
        return ops;
    }
};
