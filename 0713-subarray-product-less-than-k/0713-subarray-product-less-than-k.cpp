class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        int n=arr.size();
        int prod=1;
        int maxi=0;
        int left=0;
        for(int right=0;right<n;right++){
            prod*=arr[right];
            while(prod>=k&&left<=right){
                prod/=arr[left];
                left++;
            }
            maxi+=right-left+1;
        }
        return maxi;
    }
};