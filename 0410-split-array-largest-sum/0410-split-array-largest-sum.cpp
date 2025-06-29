class Solution {
public:
    bool isvalid(vector<int>& arr,int n,int k,int mid){
        int student=1,pages=0;
        for(int i=0;i<n;i++){
            if(arr[i]>mid){
                return false;
            }
            else if(arr[i]+pages<=mid){
                pages=pages+arr[i];
            }else{
                student++;
                pages=arr[i];
            }
        }
        if(student>k){
            return false;
        }else{
            return true;
        }

    }
    int splitArray(vector<int>& arr, int k) {
        int n=arr.size();
        int low=0;
        int high=accumulate(arr.begin(), arr.end(), 0);
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(isvalid(arr,n,k,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;

        
    }
};