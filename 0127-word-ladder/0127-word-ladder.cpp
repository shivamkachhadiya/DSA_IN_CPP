class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end()) return 0;
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        visited.insert(beginWord);
        
        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();
            
            if (current == endWord) return steps;
            
            for (int i = 0; i < current.size(); ++i) {
                char original = current[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == original) continue;
                    current[i] = c;
                    if (wordSet.find(current) != wordSet.end() && visited.find(current) == visited.end()) {
                        if (current == endWord) return steps + 1;
                        visited.insert(current);
                        q.push({current, steps + 1});
                    }
                }
                current[i] = original;
            }
        }
        return 0;
    }
};