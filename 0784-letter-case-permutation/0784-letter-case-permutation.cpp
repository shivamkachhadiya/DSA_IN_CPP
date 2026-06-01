class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        dfs(s, 0, res);
        return res;
    }
    
    void dfs(string &s, int i, vector<string> &res) {
        if(i == s.size()) {
            res.push_back(s); // ek permutation add karo
            return;
        }
        if(isalpha(s[i])) {
            s[i] = tolower(s[i]); // chhota
            dfs(s, i+1, res);
            s[i] = toupper(s[i]); // bada
            dfs(s, i+1, res);
        } else {
            dfs(s, i+1, res); // digit same rahega
        }
    }
};
