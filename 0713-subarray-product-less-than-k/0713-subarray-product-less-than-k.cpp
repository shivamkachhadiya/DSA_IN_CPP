class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
                if(k <= 1) return 0; // edge case
        int n=arr.size();
        int left=0;
        int maxCount=0;
        long long prod=1;
        for(int right=0;right<n;right++){
            prod*=arr[right];
            while(prod>=k){
                prod/=arr[left];
                left++;
            }
            maxCount+=(right-left+1);
        }
        return maxCount;
    }
};