class Solution {
public:
    int search(vector<int>& arr, int key) {
         int n=arr.size();
        int start=0;
        int end=n-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(arr[mid]==key)return mid;
            if(arr[start]<=arr[mid]){
                //left half sorted
                if(arr[start]<=key && key<=arr[mid]){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }else{
                //right half sorted
                if (arr[mid] <= key && key <= arr[end]) {
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};