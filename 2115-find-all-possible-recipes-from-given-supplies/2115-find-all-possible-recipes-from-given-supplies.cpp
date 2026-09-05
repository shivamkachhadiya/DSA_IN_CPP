class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, 
                                  vector<vector<string>>& ingredients, 
                                  vector<string>& supplies) {
        int n = recipes.size();
        
        // adj list: ingredient → list of (recipeIndex, recipeName)
        unordered_map<string, vector<pair<int,string>>> adj;
        vector<int> indegree(n, 0);
        
        // Build graph
        for (int i = 0; i < n; i++) {
            for (auto &ing : ingredients[i]) {
                adj[ing].push_back({i, recipes[i]});
                indegree[i]++; // recipe i needs this ingredient
            }
        }
        
        // Set of supplies
        unordered_set<string> st(supplies.begin(), supplies.end());
        
        queue<string> q;
        for (auto &s : supplies) q.push(s);
        
        vector<string> ans;
        
        // Kahn’s algorithm BFS
        while (!q.empty()) {
            string cur = q.front(); q.pop();
            
            // If current ingredient helps some recipes
            for (auto &p : adj[cur]) {
                int idx = p.first;
                string rec = p.second;
                
                indegree[idx]--;
                if (indegree[idx] == 0) {
                    ans.push_back(rec);
                    q.push(rec);   // cooked recipe becomes new supply
                    st.insert(rec);
                }
            }
        }
        
        return ans;
    }
};
