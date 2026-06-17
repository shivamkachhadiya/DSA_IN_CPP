class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double i = 0;
        double j = 0;
        vector<double> ans;
        double n1 = nums1.size();
        double n2 = nums2.size();
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                ans.push_back(nums1[i]);
                i++;
            } else {
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while (i < n1) {
            ans.push_back(nums1[i]);
            i++;
        }

        while (j < n2) {
            ans.push_back(nums2[j]);
            j++;
        }
        int length = ans.size();
        if (length % 2 == 0) {
            double start = 0;
            double end = length - 1;
            double mid = (start + end) / 2;
            double new_mid = mid + 1;
            double sum = ans[mid] + ans[new_mid];
            return sum / 2;
        } else {
            double start = 0;
            double end = length - 1;
            double mid = (start + end) / 2;
            return ans[mid];
        }
    }
};
