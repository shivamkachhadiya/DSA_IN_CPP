class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int i, bool swapp) {
        if (i == nums1.size())
            return 0;

        int ans = INT_MAX;

        int prev1 = nums1[i - 1];
        int prev2 = nums2[i - 1];

        // catch
        if (swapp) {
            swap(prev1, prev2);
        }

        // not take
        if (nums1[i] > prev1 && nums2[i] > prev2) {
            ans = solve(nums1, nums2, i + 1, 0);
        }

        // swap

        if (nums1[i] > prev2 && nums2[i] > prev1) {
            ans = min(ans, 1 + solve(nums1, nums2, i + 1, 1));
        }

        return ans;
    }

    int solveTab(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        for (int index = n - 1; index >= 1; index--) {
            for (int swapped = 1; swapped >= 0; swapped--) {

                int ans = INT_MAX;

                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // catch
                if (swapped) {
                    swap(prev1, prev2);
                }

                // not take
                if (nums1[index] > prev1 && nums2[index] > prev2) {
                    ans = dp[index + 1][0];
                }

                // swap

                if (nums1[index] > prev2 && nums2[index] > prev1) {
                    ans = min(ans, 1 + dp[index + 1][1]);
                }

                dp[index][swapped]= ans;
            }
        }
        return dp[1][0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        bool swapp = 0;
        // return solve(nums1,nums2,1,false);
        return solveTab(nums1,nums2);
    }
};