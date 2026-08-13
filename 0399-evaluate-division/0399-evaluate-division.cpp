class Solution {
public:
    void dfs(unordered_map < string, vector<pair<string, double>>> &adj,string &src,string &dst,
                unordered_set<string>&vis,double prod,double &ans){
                    if(vis.find(src)!=vis.end())return;
                    vis.insert(src);
                    if(src==dst){
                        ans=prod;
                        return;
                    }
                    for(auto &p:adj[src]){
                        string v=p.first;
                        double val=p.second;
                        dfs(adj,v,dst,vis,prod*val,ans);
                    }
                }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        int n = equations.size();
        unordered_map < string, vector<pair<string, double>>> adj;
        for (int i = 0; i < n; i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            adj[u].push_back({v, values[i]});
            adj[v].push_back({u, 1 / values[i]});
        }
        vector<double>results;
        for(auto &query:queries){
            string src=query[0];
            string dst=query[1];
            double ans=-1.0;
            double prod=1.0;

            if(adj.find(src)!=adj.end()){
                unordered_set<string>vis;
                dfs(adj,src,dst,vis,prod,ans);
            }
             results.push_back(ans);
        }
        return results;
    }
};