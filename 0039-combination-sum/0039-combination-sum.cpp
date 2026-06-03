class Solution {
public:
    void solve(vector<int>&arr,int target,int n,vector<int>&part,vector<vector<int>>&ans,
                int i,int sum){
                
                if(i==n){
                    if(sum==target){
                        ans.push_back(part);
                        return;
                    }
                    return;
                }

                if(sum==target){
                    ans.push_back(part);
                    return;
                }

                if(sum>target){
                    return;
                }

            //pick
            part.push_back(arr[i]);
            solve(arr,target,n,part,ans,i,sum+arr[i]);

            part.pop_back();

            solve(arr,target,n,part,ans,i+1,sum);

    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n=arr.size();
        vector<int>part;
        vector<vector<int>>ans;
        solve(arr,target,n,part,ans,0,0);
        return ans;
    }
};