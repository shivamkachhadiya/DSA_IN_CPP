class Solution {
public:
vector<vector<int>>ans;
    void solve(vector<int>&arr,int target,vector<int>&part,int n,int i,int currsum){
        if(i==n){
            if(currsum==target){
                ans.push_back(part);
                return;
            }
            return;
        }
        if(currsum>target)return;
        if(currsum==target){
            ans.push_back(part);
            return;
        }
       
        part.push_back(arr[i]);
        solve(arr,target,part,n,i,currsum+arr[i]);
        part.pop_back();
        solve(arr,target,part,n,i+1,currsum);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int>part;
        int n=arr.size();
        solve(arr,target,part,n,0,0);
        return ans;
    }
};