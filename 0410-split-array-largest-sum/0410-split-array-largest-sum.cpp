class Solution {
public:
    bool isPossible(vector<int>&arr,int k,int mid){
        int total=0;
        int days=0;
        for(int i=0;i<arr.size();i++){
            if(total+arr[i]<=mid){
                total+=arr[i];
            }else{
                days++;
                total=arr[i];
            }
        }
        return days<k;
    }
    int splitArray(vector<int>& arr, int k) {
        int n=arr.size();
        int start=*max_element(arr.begin(),arr.end());
        int end=accumulate(arr.begin(),arr.end(),0);
        int ans=0;
        while(start<=end){
            int mid=(start+end)/2;
            if(isPossible(arr,k,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};