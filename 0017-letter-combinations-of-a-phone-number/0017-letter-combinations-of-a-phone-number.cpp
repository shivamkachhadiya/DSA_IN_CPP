class Solution {
public:
    void solve(string digits,vector<string>&ans,int n,vector<string> mapping,int i,string part){
        if(i>=digits.size()){
            ans.push_back(part);
            return;
        }
        int val=digits[i]-'0';
        string mapping_string=mapping[val];

        for(int j = 0; j < mapping_string.size(); j++){
            part.push_back(mapping_string[j]);
            solve(digits,ans,n,mapping,i+1,part);
            part.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        int n = digits.length();
        vector<string> mapping = {"",    "",    "abc",  "def", "ghi",
                             "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string output="";
        solve(digits,ans,n,mapping,0,output);
        return ans;
    }
};