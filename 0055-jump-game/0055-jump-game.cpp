class Solution {
public:
    bool canJump(vector<int>& arr) {
        int maxi = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (maxi < i)
                return false;

            maxi = max(maxi, i + arr[i]);
        }
        return true;
    }
};