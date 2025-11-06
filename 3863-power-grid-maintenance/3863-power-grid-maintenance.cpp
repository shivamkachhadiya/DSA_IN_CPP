#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x) {
        if (x != parent[x]) parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        // Step 1: Build connected components
        for (auto& e : connections)
            dsu.unite(e[0], e[1]);

        // Step 2: Collect nodes per component
        unordered_map<int, vector<int>> compNodes;
        for (int i = 1; i <= c; i++)
            compNodes[dsu.find(i)].push_back(i);

        // Step 3: Initialize sets for online stations
        unordered_map<int, set<int>> compOnline;
        for (auto& [root, nodes] : compNodes)
            compOnline[root] = set<int>(nodes.begin(), nodes.end());

        vector<bool> online(c + 1, true);
        vector<int> result;

        // Step 4: Process queries
        for (auto& q : queries) {
            int type = q[0], x = q[1];
            int root = dsu.find(x);

            if (type == 1) {
                if (online[x]) {
                    result.push_back(x);
                } else {
                    if (!compOnline[root].empty())
                        result.push_back(*compOnline[root].begin());
                    else
                        result.push_back(-1);
                }
            } else if (type == 2) {
                if (online[x]) {
                    online[x] = false;
                    compOnline[root].erase(x);
                }
            }
        }

        return result;
    }
};
