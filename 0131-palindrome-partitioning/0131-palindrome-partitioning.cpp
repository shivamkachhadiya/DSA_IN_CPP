class Solution {
public:
    vector<vector<string>> result;
    bool isPalindrome(string& s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    void solve(string &s,int start,vector<string>&path){
        if (start == s.length()) {
            result.push_back(path);
            return;
        }

        for(int i=start;i<s.size();i++){
            if(isPalindrome(s,start,i)){
                //pick add in curr
                path.push_back(s.substr(start,i-start+1));

                //recursive
                solve(s,i+1,path);

                //backtrack
                path.pop_back();
            }
        }


    }

    vector<vector<string>> partition(string s) {
        vector<string> path;
        solve(s, 0, path);
        return result;
    }
};