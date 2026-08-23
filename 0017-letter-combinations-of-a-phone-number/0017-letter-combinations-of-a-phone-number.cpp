class Solution {
public:
    unordered_map<char,string>ask_map{
     {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"}
    };
    vector<string>ans;

    void solve(string digits,string& part,int idx){
        if(idx==digits.size()){
            ans.push_back(part);
            return;
        }
        string curr_string=ask_map[digits[idx]];
      
        for(int i=0;i<curr_string.size();i++){
            part.push_back(curr_string[i]);
            solve(digits,part,idx+1);
            part.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string part="";
        solve(digits,part,0);
        return ans;
    }
};