class Solution {
public:
     bool isValid(vector<int>&arr,int m,int mid){
        int n=arr.size();
        int last_placed=0;
        int count=1;
        for(int i=1;i<n;i++){
            int diff=abs(arr[i]-arr[last_placed]);
            if(diff>=mid){
                count++;
                last_placed=i;
            }
        }
        if(count>=m)return true;
        return false;
     }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int start=1;
        int maxi=*max_element(position.begin(),position.end());
        int end=maxi;
        int ans=-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(isValid(position,m,mid)){
                ans=mid;
                start=mid+1;
            }else{
                end=mid-1;
            }
        }
        return ans;
    }
};