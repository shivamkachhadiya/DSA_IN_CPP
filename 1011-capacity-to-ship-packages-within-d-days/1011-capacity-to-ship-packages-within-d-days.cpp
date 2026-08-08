class Solution {
public:
    bool isValid(vector<int>&arr,int mid,int days){
        int total_days=1;
        int curr_weight=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>mid)return false;
            curr_weight+=arr[i];
            if(curr_weight>mid){
                total_days++;
                curr_weight=arr[i];
            }
        }
        return total_days<=days;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int start=*max_element(arr.begin(),arr.end());
        int ans=-1;
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