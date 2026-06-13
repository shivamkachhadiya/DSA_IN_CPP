class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        int j = 0;
        int k=0;
        int n_=nums1.size();
        vector<int>ans(n_);
        while (i < m && j < n) {
            if(nums1[i]<nums2[j]){
                ans[k]=nums1[i];
                k++;
                i++;
            }else{
                ans[k]=nums2[j];
                k++;
                j++;
            }
        }
        while(i<m){
            ans[k]=nums1[i];
            k++;
            i++;
        }
        while(j<n){
            ans[k]=nums2[j];
            k++;
            j++;
        }
        nums1=ans;
    }
};