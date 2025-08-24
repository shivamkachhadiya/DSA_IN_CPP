class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int i=0;
        int j=0;
        int m=nums1.size();
        int n=nums2.size();
        vector<int>temp;
        while(i<m&&j<n){
            if(nums1[i]<=nums2[j]){
                temp.push_back(nums1[i]);
                i++;
            }else{
                temp.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            temp.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            temp.push_back(nums2[j]);
            j++;
        }

        nums1 = temp;
        int size = nums1.size();
        int mid = size / 2;

        if (size % 2 == 0) {
            return (nums1[mid - 1] + nums1[mid]) / 2.0;  // ✅ fix for even
        } else {
            return nums1[mid];  // ✅ fix for odd
        }

        return -1;
        
    }
};



