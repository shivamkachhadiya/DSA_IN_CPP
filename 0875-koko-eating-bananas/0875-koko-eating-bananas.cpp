class Solution {
public:
    inline int isPossible(const vector<int>&arr,const int mid,const int max_time_take){
        long long total_time=0;
        for(int i=0;i<arr.size();i++){
            long long currTime=ceil((double)arr[i]/mid);
            total_time+=currTime;
        }
        return total_time<=max_time_take;
    }
    int minEatingSpeed(vector<int>& arr, int h) {
        int n=arr.size();
        int start=1;
        int end=*max_element(arr.begin(),arr.end());
        int ans=0;
        while(start<=end){
            int mid=(start+end)/2;

            if(isPossible(arr,mid,h)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};