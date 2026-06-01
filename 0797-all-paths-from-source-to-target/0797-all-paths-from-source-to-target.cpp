class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& graph, int node) {
        path.push_back(node); // current node add karo
        if(node == graph.size()-1) {
            res.push_back(path); // agar last node hai to ek path store karo
        } else {
            for(int nei : graph[node]) {
                dfs(graph, nei); // next node par jao
            }
        }
        path.pop_back(); // backtrack
    }
};
