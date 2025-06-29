class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // int n = nums.size();
        //  better solution of this code:
        //   sort(nums.begin(), nums.end());
        //   int largest = 1;
        //   int countcurr = 0;
        //   int lastsmall = INT_MIN;
        //   if (nums.size() == 0) {
        //       largest = 0;
        //   } else {
        //       for (int i = 0; i < n; i++) {

        //         if (nums[i] - 1 == lastsmall) {
        //             countcurr++;
        //             lastsmall = nums[i];

        //         } else if (nums[i] != lastsmall) {
        //             countcurr = 1;
        //             lastsmall = nums[i];
        //         }
        //         largest = max(largest, countcurr);
        //     }
        // }
        // return largest;

        unordered_set<int> uset;
        for (int val : nums) {
            uset.insert(val);
        }
        int n = uset.size();

        int largest=1;
        if (n == 0)
            largest = 0;

        for (auto it : uset) {
            // if not find
            if (uset.find(it - 1) == uset.end()) {
                int count = 1;
                int x = it;
                while (uset.find(x + 1) != uset.end()) { // if find
                    x++;
                    count++;
                }
                largest = max(largest, count);
            }
        }
        return largest;
    }
};