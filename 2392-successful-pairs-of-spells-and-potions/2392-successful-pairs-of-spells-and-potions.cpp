class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> res(n);
        
        // Sort potions for binary search
        sort(potions.begin(), potions.end());
        
        for (int i = 0; i < n; i++) {
            long long target = (success + spells[i] - 1) / spells[i]; // ceil division
            
            // Binary search to find first potion >= target
            int left = 0, right = m - 1, idx = m;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (potions[mid] >= target) {
                    idx = mid;
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            
            res[i] = m - idx; // number of successful pairs
        }
        
        return res;
    }
};
