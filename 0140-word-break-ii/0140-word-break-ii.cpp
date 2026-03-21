class Solution {
public:
    unordered_map<string, vector<string>> memo;

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (memo.count(s)) return memo[s];
        
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> result;

        // Base case: if the whole string is a word, add it to results
        if (dict.count(s)) {
            result.push_back(s);
        }

        for (int i = 1; i < s.length(); i++) {
            string left = s.substr(0, i);
            
            if (dict.count(left)) {
                string right = s.substr(i);
                vector<string> subResults = wordBreak(right, wordDict);
                
                for (string sub : subResults) {
                    result.push_back(left + " " + sub);
                }
            }
        }

        return memo[s] = result;
    }
};