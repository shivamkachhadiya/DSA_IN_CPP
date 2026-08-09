class Solution {
public:
    bool isValid(vector<int>&arr,int maximum_allow_partition,int max_allow_val){
        int partition=1;
        int sum=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            if(sum>max_allow_val){
                sum=arr[i];
                partition++;
            }
        }
        return partition<=maximum_allow_partition;
    }
    int splitArray(vector<int>& arr, int k) {
        int start=*max_element(arr.begin(),arr.end());
        int end=accumulate(arr.begin(),arr.end(),0);
        int ans=0;
        while(start<=end){
            int mid=(start+end)/2;
            if(isValid(arr,k,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};