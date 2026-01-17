class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        while(i<=n-2){
            if(arr[i]<arr[i+1]){
                i++;
            }else{
                return i;
                break;
            }
        }
        return -1;
    }
};