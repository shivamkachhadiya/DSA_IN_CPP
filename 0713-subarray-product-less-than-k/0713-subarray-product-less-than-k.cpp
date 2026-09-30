class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int k) {
        int n=arr.size();
                if (k <= 1) return 0;

        int maxProd=1;
        int left=0;
        int count=0;

        for(int right=0;right<n;right++){
            maxProd*=arr[right];
           

            while(maxProd>=k){
                maxProd/=arr[left];
                left++;
            }

            count+=right-left+1;
            
        }
        return count;
    }
};