class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st; 
        string ans;
        stringstream ss(path);
        string token;
        
        // path ko "/" ke basis par todte hain
        while (getline(ss, token, '/')) {
            if (token == "" || token == ".") {
                // khali ya current dir ignore
                continue;
            } else if (token == "..") {
                // ek step peeche jana hai
                if (!st.empty()) st.pop_back();
            } else {
                // valid folder push karna hai
                st.push_back(token);
            }
        }
        
        // final path banana
        for (string s : st) {
            ans += "/" + s;
        }
        
        // agar ans empty hai to root return karo
        return ans.empty() ? "/" : ans;
    }
};
