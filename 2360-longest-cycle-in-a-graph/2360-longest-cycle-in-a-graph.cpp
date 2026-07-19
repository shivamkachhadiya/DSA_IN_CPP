class Solution {
public:
    int result = -1;

    void dfs(vector<int>& edges, int n, vector<bool>& vis, vector<int>& count,
             vector<bool>& inRecPath, int startNode) {
        vis[startNode] = true;
        inRecPath[startNode] = true;

        if (edges[startNode] != -1) {
            if (vis[edges[startNode]] == false) {
                count[edges[startNode]] = count[startNode] + 1;
                dfs(edges,n,vis,count,inRecPath,edges[startNode]);
            }else if(inRecPath[edges[startNode]]==true){
                result=max(result,count[startNode]-count[edges[startNode]]+1);
            }
        }
        inRecPath[startNode]=false;

    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n, false);
        vector<int> count(n, 1);
        vector<bool> inRecuPath(n, false);

        for (int i = 0; i < edges.size(); i++) {
            if (vis[i] == false) {
                dfs(edges, n, vis, count, inRecuPath, i);
            }
        }
        return result;
    }
};