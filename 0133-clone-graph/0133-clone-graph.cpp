class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        // map original node -> cloned node
        unordered_map<Node*, Node*> mp;
        
        // DFS function
        function<Node*(Node*)> dfs = [&](Node* cur) {
            if (mp.find(cur) != mp.end()) return mp[cur];
            
            // naya node banate hain
            Node* copy = new Node(cur->val);
            mp[cur] = copy;
            
            // neighbors ko clone karte hain
            for (auto nei : cur->neighbors) {
                copy->neighbors.push_back(dfs(nei));
            }
            return copy;
        };
        
        return dfs(node);
    }
};
