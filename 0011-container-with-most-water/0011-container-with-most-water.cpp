class Solution {
public:
    int maxArea(vector<int>& arr) {
        int start=0;
        int n=arr.size();
        int end=n-1;
        int ans=0;
        while(start<=end){
            int width=end-start;
            int height=min(arr[start],arr[end]);
            int temp=width*height;
            ans=max(ans,temp);
            if(arr[start]<=arr[end]){
                start++;
            }else{
                end--;
            }

        }
        return ans;
    }
};