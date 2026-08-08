class Solution {
public:
    // 2 sum  n1+n2=target
    // 3 sum n1+n2+n3=target
    // convert n2+n3=0-n1
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int n1 = arr[i];
            int start = i + 1;
            int end = n - 1;
            int target = -n1;

            while (start < end) {  
                int sum=arr[start]+arr[end];
                if (sum == target) {
                    int n2 = arr[start];
                    int n3 = arr[end];
                    ans.push_back({n1, n2, n3});
                    while(start<end&&arr[start]==arr[start+1])start++;
                    while(start<end&&arr[end]==arr[end-1])end--;
                    start++;
                    end--;                
                }else if(sum>target){
                    end--;
                }else{
                    start++;
                }
            }
            while(i+1<n&&arr[i]==arr[i+1])i++;
        }
        return ans;
    }
};