class WordDictionary {
    struct TrieNode {
        bool isEnd;
        TrieNode* children[26];
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };
    
    TrieNode* root;
    
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true; // word end mark karo
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }
    
    bool dfs(string &word, int i, TrieNode* node) {
        if (!node) return false;
        if (i == word.size()) return node->isEnd;
        
        if (word[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (dfs(word, i+1, node->children[j])) return true;
            }
            return false;
        } else {
            int idx = word[i] - 'a';
            return dfs(word, i+1, node->children[idx]);
        }
    }
};
