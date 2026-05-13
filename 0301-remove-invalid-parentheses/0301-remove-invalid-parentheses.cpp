class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        bool found = false;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();
                
                if (isValid(curr)) {
                    result.push_back(curr);
                    found = true;
                }
                
                if (found) continue;
                
                for (int j = 0; j < curr.size(); ++j) {
                    if (curr[j] != '(' && curr[j] != ')') continue;
                    string next = curr.substr(0, j) + curr.substr(j + 1);
                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
            if (found) break;
        }
        return result;
    }
    
    bool isValid(const string& s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') balance++;
            else if (c == ')') {
                balance--;
                if (balance < 0) return false;
            }
        }
        return balance == 0;
    }
};