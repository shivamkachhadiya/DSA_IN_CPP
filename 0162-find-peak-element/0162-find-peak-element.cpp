class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n=arr.size();
        int start=0;
        int end=n-1;
        int ans=0;
        while(start<end){
            int mid = start + (end - start) / 2;
            if(arr[mid]<arr[mid+1]){
                //left sorted
                ans=max(ans,mid);
                start=mid+1;
            }else{
                //right sorted
                ans=max(ans,mid);
                end=mid;
            }
        }
        return start;       
    }
};