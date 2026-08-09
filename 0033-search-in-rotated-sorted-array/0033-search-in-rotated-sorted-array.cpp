class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]==target)return mid;
            if(arr[start]<=arr[mid]){
                //left half sorted
                if(arr[start]<=target&&target<=arr[mid]){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }else{
                //right half sorted
                if(arr[mid]<target&&target<=arr[end]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};