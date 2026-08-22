class Solution {
public:
    string reverseWords(string s) {
        vector<string> temp;
        int n = s.size();
        string curr = "";
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                if(!curr.empty()){
                temp.push_back(curr);
                curr = "";
                }
            } else {
                curr.push_back(s[i]);
            }
        }
        if(!curr.empty())temp.push_back(curr);

        string final_string = "";
        for (int j = temp.size() - 1; j >= 0; j--) {
            final_string+=(temp[j]);
            if(j>0)final_string+=(" ");
        }
        return final_string;
    }
};