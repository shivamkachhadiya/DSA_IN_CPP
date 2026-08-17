class Solution {
public:
unordered_set<int>st;
vector<vector<int>>ans;
    void solve(vector<int>&arr,vector<int>&temp){
        if(temp.size()==arr.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<arr.size();i++){
            if(st.find(arr[i])==st.end()){
                st.insert(arr[i]);
                temp.push_back(arr[i]);

                solve(arr,temp);

                temp.pop_back();
                st.erase(arr[i]);
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& arr) {
        int n=arr.size();
        vector<int>temp;
        solve(arr,temp);
        return ans;
    }
};