class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int temp1=0,temp2=0;
                vector<int> temp;   // extra space

        while(temp1<m && temp2<n){
            if(nums1[temp1]<=nums2[temp2]){
                temp.push_back(nums1[temp1]);
                temp1++;
            }else{
                temp.push_back(nums2[temp2]);
                temp2++;
            }
        }
        while(temp1<m){
            temp.push_back(nums1[temp1]);
            temp1++;
        }
        while(temp2<n){
            temp.push_back(nums2[temp2]);
            temp2++;
        }

        nums1=temp;


    }
};