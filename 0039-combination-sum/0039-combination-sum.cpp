class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& arr, int target, int i, vector<int>& part,
               int sum) {
        if (i >= arr.size()) {
            if (sum == target) {
                ans.push_back(part);
                return;
            }
            return;
        }
        if (sum == target) {
            ans.push_back(part);
            return;
        }

        if(sum>target)return;

        part.push_back(arr[i]);
        solve(arr,target,i,part,sum+arr[i]);
        part.pop_back();
        solve(arr,target,i+1,part,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> part;
        solve(arr, target, 0, part, 0);
        return ans;
    }
};