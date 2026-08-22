class Solution {
public:
    void solve(int n,int k,vector<vector<int>>&ans,vector<int>&part,int i){
        if(k==0){
            ans.push_back(part);
            return;
        }
        if(i>n){
            return;
        }

        for(int start=i;start<=n;start++){
            part.push_back(start);
            solve(n,k-1,ans,part,start+1);
            part.pop_back();
        }

        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>part;
        solve(n,k,ans,part,1);
        return ans;
    }
};