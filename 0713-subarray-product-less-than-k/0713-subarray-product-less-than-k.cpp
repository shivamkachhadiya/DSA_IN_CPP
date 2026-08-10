class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        int n=arr.size();
        int left=0;
        int prod=1;
        int count=0;
        if(k<=1)return 0;
        for(int r=0;r<n;r++){
            prod*=arr[r];
            while(prod>=k){
                prod/=arr[left];
                left++;
            }
            count+=r-left+1;
        }
        return count;
    }
};