class Solution {
public:
    int lowerbound(vector<int>arr,int n,int x){
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=x){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
       int uperbound(vector<int>arr,int n,int x){
        int low=0,high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>x){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>tmp;
        
        int lb=lowerbound(arr,n,k);
        if(lb==n||arr[lb]!=k){
            tmp.push_back(-1);
            tmp.push_back(-1);
        }
        else{
            //return (lb,uperbound(arr,n,k)-1);
            tmp.push_back(lb);
            int up=uperbound(arr,n,k)-1;
            tmp.push_back(up);
        }
        return tmp;
    }
};