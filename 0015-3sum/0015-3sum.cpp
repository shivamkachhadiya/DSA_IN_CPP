class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n=arr.size();
       // vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        set<vector<int>>my_set;
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=arr[i]+arr[j]+arr[k];
                if(sum==0){
                    my_set.insert({arr[i],arr[j],arr[k]});
                }
                if(sum>0){
                    k--;
                }else{
                    j++;
                }
            }
        }
          vector<vector<int>> ans(my_set.begin(), my_set.end());
        return ans;
    }
};