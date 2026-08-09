class Solution {
public:
    int isValid(vector<int>&arr,int mid,int th){
        int sum=0;
        int total=0;
        for(int i=0;i<arr.size();i++){
            sum+=ceil((double)arr[i]/mid);
        }
        return sum<=th;
    }
    int smallestDivisor(vector<int>& arr, int threshold) {
        int n=arr.size();
        int ans=-1;
        int start=1;
        int end = *max_element(arr.begin(), arr.end()); // upper bound
        while(start<=end){
            int mid=(start+end)/2;
            if(isValid(arr,mid,threshold)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};