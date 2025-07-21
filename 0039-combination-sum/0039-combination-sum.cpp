class Solution {
public:
    // void findCombination(int ind, int target, vector<int>& arr,
    //                      vector<vector<int>>& ans, vector<int>& ds) {
    //     // if (ind == arr.size()) {
    //     //     if (target == 0) {
    //     //         ans.push_back(ds);
    //     //     }
    //     //     return;
    //     // }

    //     // // pick up element
    //     // if (arr[ind] <= target) {
    //     //     ds.push_back(arr[ind]);
    //     //     findCombination(ind, target - arr[ind], arr, ans, ds);
    //     //     ds.pop_back();
    //     // }

    //     // findCombination(ind + 1, target, arr, ans, ds);

    // }
  set<vector<int>> s;

void getAllCombinations(vector<int>& arr, int idx, int tar, vector<vector<int>>& ans, vector<int>& combin) {
    if(idx == arr.size() || tar < 0) {
        return;
    }

    if(tar == 0) {
        if(s.find(combin) == s.end()) {
            ans.push_back(combin);
            s.insert(combin);
        }
        return;
    }

    combin.push_back(arr[idx]);
    //single
    getAllCombinations(arr, idx+1, tar - arr[idx], ans, combin);
    //multiple
    getAllCombinations(arr, idx, tar - arr[idx], ans, combin);
    combin.pop_back();

    //exclusion
    getAllCombinations(arr, idx+1, tar, ans, combin);
}

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<vector<int>> ans;
        vector<int>combin;
        getAllCombinations(arr,0,target,ans,combin);
        //vector<int> ds;
        // findCombination(0, target, candidates, ans, ds);
        return ans;
    }
};