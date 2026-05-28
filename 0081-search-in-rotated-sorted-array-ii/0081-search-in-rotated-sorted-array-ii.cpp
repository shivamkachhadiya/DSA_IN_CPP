class Solution {
public:
    bool search(vector<int>& arr, int target) {
        sort(arr.begin(),arr.end());
          int start=0;
        int n=arr.size();
        int end=n-1;
        while(start<=end){

            int mid=(start+end)/2;

            if(arr[mid]==target)return true;

            if(arr[start]<=arr[mid]){
                //left sorted
                if(arr[start]<=target && target<=arr[mid]){
                    end=mid-1;
                }else{
                    start=mid+1;
                }
            }else{
                //right sorted
                if(arr[mid]<=target && target<=arr[end]){
                    start=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return false;
    }
};