class Solution {
public:
    vector<vector<string>>ans;
    bool isPali(string &s,int start,int end){
        while(start<end){
            if(s[start]!=s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(string& s,int idx,vector<string>&part){
        if(idx==s.size()){
            ans.push_back(part);
            return;
        }
        for(int i=idx;i<s.size();i++){
            if(isPali(s,idx,i)){
                part.push_back(s.substr(idx,i-idx+1));
                solve(s,i+1,part);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string>part;
        solve(s,0,part);
        return ans;
    }
};