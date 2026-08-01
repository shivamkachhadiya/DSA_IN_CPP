class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        if(n==1)return arr[0];
        if(arr[0]!=arr[1])return arr[0];
        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                continue;
            }else if(arr[i]!=arr[i-1]&&arr[i]!=arr[i+1]){
                return arr[i];
                break;
            }
        }
        return -1;
    }
};