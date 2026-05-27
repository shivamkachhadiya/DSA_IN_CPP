class Solution {
public:
    void solve(vector<int>&arr,int target,vector<int>&part,vector<vector<int>>&ans,int i,int sum){
        if(i>=arr.size()){
            if(sum==target){
                ans.push_back(part);
            }
                return;
            
        }

        if(sum==target){
            ans.push_back(part);
            return;
        }

        if(sum>target)return;

        part.push_back(arr[i]);
        solve(arr,target,part,ans,i,sum+arr[i]);
        part.pop_back();
        solve(arr,target,part,ans,i+1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>part;
        vector<vector<int>>ans;
        solve(candidates,target,part,ans,0,0);
        return ans;
    }
};