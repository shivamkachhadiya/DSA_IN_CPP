class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        set<vector<int>> st;  
        for(int i=0;i<n;i++){

            int j=i+1;
            int k=n-1;

            while(j<k){
                if(arr[i]+arr[j]+arr[k]==0){
                    st.insert({arr[i],arr[j],arr[k]});
                    j++;
                    k--;
                }else if(arr[i]+arr[j]+arr[k]>0){
                    k--;
                }else{
                    j++;
                }
            }

        }
        vector<vector<int>>ans(st.begin(),st.end());
        return ans;
    }
};