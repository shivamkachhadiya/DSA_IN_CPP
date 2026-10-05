class Solution {
public:
    bool isPossible(const vector<int>&arr,const int days,const int currentCapacity){
        int totalCapacity=0;
        int Totaldays=1;
        for(int i=0;i<arr.size();i++){
            totalCapacity+=arr[i];
            if(totalCapacity>currentCapacity){
                Totaldays++;
                totalCapacity=arr[i];
            }
        }
        return Totaldays<=days;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int start = *max_element(arr.begin(), arr.end());
        int ans=0;
        int end=accumulate(arr.begin(),arr.end(),0);
        while(start<=end){
            int mid=(start+end)/2;
            if(isPossible(arr,days,mid)){
                ans=mid;
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return ans;
    }
};