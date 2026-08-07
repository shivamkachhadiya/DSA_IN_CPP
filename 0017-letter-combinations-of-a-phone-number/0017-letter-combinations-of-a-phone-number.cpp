class Solution {
public:
    unordered_map<char, string> map_={
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    vector<string> ans;

    void solve(string digits, int n, int i, string temp) {
        if (i >= n) {
            ans.push_back(temp);
            return;
        }

        string str = map_[digits[i]];
        for (int idx = 0; idx < str.size(); idx++) {
            temp.push_back(str[idx]);
            solve(digits, n, i + 1, temp);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.length();
        solve(digits, n, 0, "");
        return ans;
    }
};