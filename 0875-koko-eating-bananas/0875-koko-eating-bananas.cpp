class Solution {
public:
    bool isValid(vector<int>&arr,int mid,int h){
        long long total_hours=0;
        for(int i=0;i<arr.size();i++){
            long long taken=ceil((double)arr[i]/mid);
            total_hours+=taken;
        }
        return total_hours<=h;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int n=arr.size();
        int ans=0;
        int start=1;
        int end=*max_element(arr.begin(),arr.end());
        while(start<=end){
            int mid=(start+end)/2;
            if(isValid(arr,mid,h)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};