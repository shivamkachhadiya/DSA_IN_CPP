class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int n=arr.size();
        int left=0,right=0;
        int zeros=0;
        int maxi=0;
        while(right<n){
            if(arr[right]==0)zeros++;
            while(zeros>k){
                if(arr[left]==0)zeros--;
                left++;
            }
            right++;
            maxi=max(maxi,right-left+1);
        }
        return maxi-1;
    }
};