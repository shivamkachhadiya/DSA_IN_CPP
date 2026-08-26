class Solution {
public:
    vector<vector<int>>ans;
    void solve(vector<int>&arr,int n,int k,vector<int>&part,int i){
        if(k==0){
            ans.push_back(part);
            return;
        }
        if(i>=n)return;
        part.push_back(arr[i]);
        solve(arr,n,k-1,part,i+1);
        part.pop_back();
        solve(arr,n,k,part,i+1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>arr;
        for(int i=1;i<=n;i++){
            arr.push_back(i);
        }
        vector<int>part;
        solve(arr,n,k,part,0);
        return ans;
    }
};