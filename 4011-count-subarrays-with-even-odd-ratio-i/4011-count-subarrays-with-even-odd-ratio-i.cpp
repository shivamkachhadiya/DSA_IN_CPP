class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int comparator = a / b;
        int counter = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int evencount = 0;
            int oddcount = 0;
            for (int j = i; j < n; j++) {

                if (nums[j] % 2 == 0) {
                    evencount++;
                } else {
                        oddcount++;
                }
                if (oddcount != 0) {
                    if ((double)evencount/oddcount <= (double)a/b) {
                        counter++;
                    }
                }
            }
        }
        return counter;
    }
};