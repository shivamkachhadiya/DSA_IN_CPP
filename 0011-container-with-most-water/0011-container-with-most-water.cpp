class Solution {
public:
    int maxArea(vector<int>& arr) {
        int left=0;
        int n=arr.size();
        int right=n-1;
        int maxi=INT_MIN;
        while(left<right){
            int height=min(arr[left],arr[right]);
            int width=right-left;
            int total=height*width;
            maxi=max(maxi,total);
            if(arr[left]<arr[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxi;
    }
};