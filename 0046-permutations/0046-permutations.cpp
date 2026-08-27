class Solution {
public:
    unordered_set<int>st;
    vector<vector<int>>ans;

    void solve(vector<int>&arr,vector<int>&part){
        if(part.size()==arr.size()){
            ans.push_back(part);
            return;
        }

        for(int i=0;i<arr.size();i++){
            if(st.find(arr[i])==st.end()){
                part.push_back(arr[i]);
                st.insert(arr[i]);

                solve(arr,part);

                part.pop_back();
                st.erase(arr[i]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& arr) {
        int n=arr.size();
        vector<int>part;
        solve(arr,part);
        return ans;    
    }
};