class Solution {
public:
    vector<vector<string>>final_ans;
    bool isPali(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void solve(string s,int n,int start,vector<string>&part){
        if(start==n){
            final_ans.push_back(part);
            return;
        }
        for(int i=start;i<n;i++){
            if(isPali(s,start,i)){
                part.push_back(s.substr(start,i-start+1));
                solve(s,n,i+1,part);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>part;
        solve(s,s.size(),0,part);
        return final_ans;    
    }
};