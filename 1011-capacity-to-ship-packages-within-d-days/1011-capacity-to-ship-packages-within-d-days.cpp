class Solution {
public:
    bool isValid(vector<int>&arr,int mid,int days){
        int total_w=0;
        int days_taken=1;
        for(int i=0;i<arr.size();i++){
            total_w+=arr[i];
            if(total_w>mid){
                days_taken++;
                total_w=arr[i];
            }
        }
        return days_taken<=days;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int n=arr.size();
        int ans=0;
        int start=*max_element(arr.begin(),arr.end());
        int end=accumulate(arr.begin(),arr.end(),0);
        while(start<=end){
            int mid=(start+end)/2;
            if(isValid(arr,mid,days)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};